query quiz 1
============

*This problem set was originally in Chinese, from Chpater 2 of __Introduction to
Database System__ (Edition 4, Wang Shan and Sa Shixuan).*

Description (zh-CN)
-------------------

设有一个 SPJ 数据库, 包括 S, P, J, SPJ, 4 个关系模式:

```
S (SNO, SNAME, STATUS, CITY);
P (PNO, PNAME, COLOR, WEIGHT);
J (JNO, JNAME, CITY);
SPJ (SNO, PNO, JNO, QTY);
```

- 供应商表 S 组成如下
  + 供应商代码 (SNO)
  + 供应商名字 (SNAME)
  + 供应商状态 (STATUS)
- 零件表 P 组成如下
  + 零件代码 (PNO)
  + 零件名 (PNAME)
  + 颜色 (COLOR)
  + 重量 (WEIGHT)
- 工程项目表 J 组成如下
  + 工程项目代码 (JNO)
  + 工程项目名 (JNAME)
  + 工程项目所在城市 (CITY)
- 供应情况表 SPJ 组成如下
  + 供应商代码 (SNO)
  + 零件代码 (PNO)
  + 工程项目代码 (JNO)
  + 供应数量 (QTY)

今有若干数据, 见 [Material](#material) 部分. 试用 SQL 语言完成如下查询:

1. 求供应工程 J1 零件的供应商号码 SNO
2. 求供应工程 J1 零件 P1 的供应商号码 SNO
3. 求供应工程 J1 零件为红色的供应商号码 SNO
4. 求没有使用天津供应商生产的红色零件的工程号 JNO
5. 求至少用了供应商 S1 所供应的全部零件的工程号 JNO

Material
--------

The files `s`, `p`, `j`, `spj` in this directory stores the text views of table
`s`, `p` and `j`, `spj`, queried from a [PostgreSQL](https://www.postgresql.org)
database, which would be my permanent choice for solving SQL (or even all
database-related) quizzes. Just read them for your go.

Solution
--------

SQL files, such as `quiz1.sql`, are basically the solutions of the quizzes. And
as I mentioned above, PostgreSQL is used right here, so be careful for possible
slight syntactic differences.
