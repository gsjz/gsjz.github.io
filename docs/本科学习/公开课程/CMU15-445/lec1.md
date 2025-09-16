# lec1-notes

## main

### flat file strawman

pure text, simple-structured

Why 'flat'? The first meaning came up to me, is the ♭ in music sheet.
Here means not-peaked, boring.

Literally, straw-man. It metaphorically refers to a simplified idea.

CSV: comma-separated value. 
Use a separate file per entity.
The application must parse the files each time they want to read or update records.

Of course there're a lot of issues.

- DATA INTEGRITY
- IMPLEMENTATION
- DURABILITY

### database management system

abbreviation: DBMS

- definition
- creation
- querying
- update
- administration

### data model

rules that define the types of things could exist and how they relate.

Schema defines the structure of database for a data model. 
Otherwise, they are random bits with no meaning.

- Relational (Most)
- Key / Value (Simple Apps / Caching)
- Graph, Document / JSON / XML / Object, Wide-Column / Column-family  (NoSQL)
- Array (Vector, Matrix, Tensor) (ML/Science)
- Hierarchical, Network, Semantic, Entity-Relationship (Obsolete / Legacy / Rare)

NoSQL means schema-less, flexible... BUT it has no strict definition.


## relational algebra

省流：就是考虑一些元组构成的集合（有时是可重集），每个元组内部有对应的属性。从而可以想象成一个列代表某属性、行代表某个组，的一张二维表。

Relational Algebra is a set of fundamental operations to retrieve and manipulate tuples in a relation. Each operator takes in one or more relations as inputs, and outputs a new relation. 

In short, the symbolic operation on the 2d table (rows consist tuples, columns consist attributes)

### Data Manipulation Languages (DMLs)

DMLs refer to the API that a DBMS exposes to applications to store and retrieve information from a database. 
There are two classes of languages for Manipulating a database: 
- Procedural: The query specifies the (high-level) execution strategy the DBMS should use to find the desired result based on sets / bags. For example, use a for loop to scan all records and count how many records are there to retrieve the number of records in the table. 
- Non-Procedural (Declarative): The query specifies only what data is wanted and not how to find it. For example, we can use SQL SELECT COUNT(\*) FROM artist to count how many records are there in the table.

### select

Select takes in a relation and outputs a subset of the tuples from that relation that satisfy a selection predicate. The predicate acts as a filter, and we can combine multiple predicates using conjunctions and disjunctions

e.g.
$$
\sigma_{predicate}(R)
$$

### projection

Projection takes in a relation and outputs a relation with tuples that contain only specified attributes.

e.g.
$$
\pi_{A1,A2,A3}(R)
$$

### union, intersection, difference, product

just like operation to set.

### join

Join takes in two relations and outputs a relation that contains all the tuples that are a combination of two tuples where for each attribute that the two relations share, the values for that attribute of both tuples is the same.

$$
R\Join S
$$



## language learning

### internship

Corresponding to fulltime positions, it's a type of job, refering not fulltime.

### seminar seires

just like discussion for specific topic.

### enroll the class

register, sign up

We can enroll in a program.

### course logistic

This word was from French, refering the skill of logic,
In 17s-18s, the French army started using it to refer the work of supply and deployment. Then the object becomes more general in English.

### course syllabus

a short list talking about what students will learn.

### plagiarism warning

steal, copy, cheat

### build something more sophisticated

more complex.

### real world entities 

object

### the first offset (after we parse a string)

offset refers the distance from the beginning. So actually it's equivalent to the index.

### deposit the money in the bank

save

### highly vetted software part

highly checked

### faculty

the group in college

### synergistic

sync

### traverse

travel across

### brittle

fragile

