## view

这个东西用普通编程语言的角度来看，约等于是定义了一个返回表的函数。每次调用它，都会重新演算。如果它涉及的底层表变了，它也会跟着改变。


## JOIN

... JOIN ... USING (名字完全相同的列名)

这个时候如果两个表里存的东西实质上是一样的语义，但是名字不太同，要怎么实现一样的 JOIN 功能？

---

默认应该是 内 JOIN，这个时候，如果同一个关键字左边的 relation 有 $cnt_1$ 行，右边的 relation 有 $cnt_2$ 行，那么生成出的笛卡尔积里，就有 $cnt_1\cdot cnt_2$ 行。

## subquery

https://duckdb.org/docs/stable/sql/expressions/subqueries.html#correlated-subqueries

大致意思就是说，如果我要只保留一个表中，每门课的 grade 最小值。那么我是要遍历每一行，对于这特定的一行，查询整个表中和这一行 course 属性一样的行中 grade 的最小值。

## 英语学习

### ...and for use in conjunction with ...

= with
