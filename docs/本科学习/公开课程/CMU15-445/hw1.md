# hw1-notes

## DuckDB

这个作业要用到 DuckDB。顺便记录下这个东西的操作方法

### load

首先是 load the dataset

???+ quote
    We can directly load the dataset when we start DuckDB:

    ```bash
    $ duckdb lahman-cmudb2025.db
    DuckDB v1.3.2 (Ossivalis) 0b83e5d2f6
    Enter ".help" for usage hints.
    ⚪◗
    ```

这里看起来有一个可爱的小设计，就是用 emoji 来象形一个鸭子的头，来模拟一般 CLI 里会有的提示用户输入的 `>`。

但是我的终端里好像并没有显示这个白色的圆？？？我的 homebrew 还有🍺来着。◗ 也是替换成了 D。

然后可以看一下里面有几个 table

???+ quote
    You can check the contents of the database by running the .tables command on the DuckDB terminal. You should see 11 tables. The output should look like this:
    
    ```bash
    ⚪◗ .tables
    appearances     collegeplaying  leagues         schools
    awardsmanagers  divisions       managers        teams
    awardsplayers   halloffame      people
    ```

### check the schema

???+ quote
    Get familiar with the schema (structure) of the tables (what attributes do they contain, what are the primary and foreign keys).

这里 primary key (foreign key) 大致的意思就是说这个字段是（不是）唯一的。好像这么说还不太准确，应该说作为 primary key，必定不能重复，反过来未必。

接下来我们打印出来 key 那一列应该就显示了信息。一张表可能有多个 primary key，作为联合主键 composite primary key，他们单独来说可以相同，但是元组捆绑起来不允许相同。

- yearID → 一年里有很多球队和球员 → 不能唯一。

- teamID → 一个球队每年有很多球员 → 不能唯一。

- playerID → 一个球员会在不同年份、不同球队都有记录 → 也不能唯一。

- 但是 (yearID, teamID, playerID) 三个加起来，就能唯一标识一条出场记录。



首先是按照二维表的样式查看当前 db 里名为 `appearances` 的 table 的 schema。

???+ quote
    Get familiar with the schema (structure) of the tables (what attributes do they contain, what are the primary and foreign keys). Run the DESCRIBE $TABLE_NAME; command on the duckdb terminal for each table. The output should look like the example below for each table.

    ```SQL
    ⚪◗ DESCRIBE appearances
    ┌─────────────┬─────────────┬─────────┬─────────┬─────────┬─────────┐
    │ column_name │ column_type │  null   │   key   │ default │  extra  │
    │   varchar   │   varchar   │ varchar │ varchar │ varchar │ varchar │
    ├─────────────┼─────────────┼─────────┼─────────┼─────────┼─────────┤
    │ yearID      │ SMALLINT    │ NO      │ PRI     │ NULL    │ NULL    │
    │ teamID      │ VARCHAR     │ NO      │ PRI     │ NULL    │ NULL    │
    │ lgID        │ VARCHAR     │ YES     │ NULL    │ NULL    │ NULL    │
    │ playerID    │ VARCHAR     │ NO      │ PRI     │ NULL    │ NULL    │
    │ G_all       │ SMALLINT    │ YES     │ NULL    │ NULL    │ NULL    │
    │ G_batting   │ SMALLINT    │ YES     │ NULL    │ NULL    │ NULL    │
    │ HR          │ SMALLINT    │ YES     │ NULL    │ NULL    │ NULL    │
    └─────────────┴─────────────┴─────────┴─────────┴─────────┴─────────┘
    ```

注意这个表格是额外生成的，一个用来表示这个 db 的 schema 的元素类型的表，而不是这个 db 本身。

这里有个很草的。我这里默认是要加一个分号

```SQL
DESCRIBE appearances;
```

才会运行😂

直接回车会认为你还没输入完。这时甚至可以删掉之前输入的东西。

???+ quote
    Contains details for player appearances. For example, this is a row from the table:

    ```bash
    2004|SFN|NL|aardsda01|11|11|0
    ```

这是怎么来的？他的意思是说你可以用 SQL 语句来查到这个记录，比如说

```sql
SELECT * FROM appearances LIMIT 5;
```

就能打出前 5 行。

### Database Schema Diagram

abbr. ERD

cmu 网站上那个图感觉有点不够高清。大概就是表示 schema 之间哪些是共用的，以及谁是 primary 谁是 foreign

### sanity check

这里指的是不严格地快速检查。

## Q1

一个 sample，List all active divisions ordered alphabetically。

直接提供了 answer，

```sql
SELECT DISTINCT division FROM divisions WHERE active = 'Y' ORDER BY division;
```
告诉我们要把 SQL query 写到 `q1_sample.duckdb.sql` 文件里面。

实际上，是可以把 `.sql` 当成纯文本文件，在里面写指令。对于 DuckDB，可以调用

```Bash
.read q1_sample.duckdb.sql
```

## Q2

### Common Table Expression

这里就是临时定义的一些表，用于后面使用.

CTE 基本形式

```sql
WITH 名字 AS (
  子查询
)
SELECT ...
FROM 名字;
```

WITH ... AS (...) 定义了一个临时结果集（相当于一张虚拟表），在后续查询里可以直接当表使用。

可以写多个，用逗号分隔。

作用类似子查询，但可读性更高，也能被复用。

`WITH ... AS` = 定义临时表（CTE），一个 WITH 可以定义不止一个临时结果集（CTE）。

如果要写多个，就在前一个 `) AS (...)` 结束后，加个逗号，然后写下一个。最后一个 CTE 后面 不能有逗号，因为后面就要跟 `SELECT ...` 主查询了。

### SQL 的解析顺序

SQL 不是逐行从左到右，大致是

1. FROM / JOIN
    
    先确定要用哪些表，怎么连接。

1. WHERE

    对上一步的结果集做过滤。

1. GROUP BY

    按照指定列把行分组。除了指定列是作为分组依据，其它每一列分组完的东西实际上是集合，没法直接输出，后续要对这些集合做聚合操作才能输出。

1. 聚合函数（SUM, MAX, AVG, ...）

    对每个组里的行做聚合运算。

1. HAVING

    可以再过滤整个分组

1. SELECT

    再从过滤后的结果里挑选需要的列。

1. DISTINCT / ORDER BY / LIMIT

    最后去重、排序、限制行数。

### COALESCE


```sql
COALESCE(expr1, expr2, expr3, ...)
```

从左到右依次检查参数，返回 第一个非 NULL 的值。

如果所有参数都是 NULL，则返回 NULL。

当我们想要对聚合后的集合找最大值时，为了处理这个集合为空的情况，我们可能就需要用 `COALESCE` 来返回一个 0。

coalesce 字面上是合并的意思。


## 英语学习

### number of games batted

这里应该是老美钟爱的棒球语境。baseball bat。

实际上这个 homework 用的 db 来自于一个棒球数据库。