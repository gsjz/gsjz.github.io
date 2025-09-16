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




## language learning

### number of games batted

这里应该是老美钟爱的棒球语境。baseball bat。

