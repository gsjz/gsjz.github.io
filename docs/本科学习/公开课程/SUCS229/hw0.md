# hw0

回顾一些非常基础的定义，只是代代定义就结束了的题。
## Q1 \[0 points\] Gradients and Hessians

recall the definition of gradient $\nabla$ and hessian $\nabla^2$
### (a)

let $f(x) = \frac{1}{2}x^T A x + b^T x$ where $A$ is a symmetric matrix in $\mathbb R^{n\times n}$ and $b\in \mathbb R ^{n}$ is a vector. what is $\nabla f(x)$? 

首先看懂 $f(x)$ 确实是一个 $\mathbb R^{n}\rightarrow \mathbb R$ 的函数。

梯度就是对每个参数对应求偏导，然后放进一个向量里。

以 $x_1$ 为例。对于后面一项显然只有 $b_1$ 乘了一下它。对于前面一项，即

$$
\frac{\partial}{\partial x_1}\sum\limits_{i=1}^{n}\sum\limits_{j=i+1}^{n} a_{i,j} x_{i}x_{j} + \frac{\partial}{\partial x_1}\frac{1}{2}a_{1,1}\cdot x_1^2
$$

第一项其实也就 $i=1$ 时有贡献，所以加起来无非是

$$
\sum\limits_{j=1}^{n} a_{1,j}x_j
$$

从而 $\nabla f(x)$ 的第一行无非就是 $A x+ b$ 的第一行，同理可以知道

$$
\nabla f(x) = Ax + b
$$

### (b)

let $g:\mathbb R \rightarrow \mathbb R$ and $h:\mathbb R^{n} \rightarrow \mathbb R$ be differentiable. if $f(x) = g(h(x))$ then

$$
f'(x) = g'(h(x))\cdot \nabla h(x)
$$

### (c)

let $f(x) = \frac{1}{2}x^T A x + b^T x$ where $A$ is a symmetric matrix in $\mathbb R^{n\times n}$ and $b\in \mathbb R ^{n}$ is a vector. what is $\nabla^2 f(x)$? 

考虑

$$
\frac{\partial^2}{\partial x_p\partial x_q} f(x)
$$

在 (a) 的思考的基础上，显然 $b^T x$ 不论怎样求导两次应该都是 $0$，所以只看前半部分。其实也是在 $(a)$ 的思考的基础上，

$$
\frac{\partial}{\partial x_{q}}\sum\limits_{j=1}^{n} a_{p,j}x_j = a_{p,q}
$$

从而

$$
\nabla^2 f(x) = A
$$

### (d)

if $f(x)=g(a^T x)$, then

$$
\nabla f(x) = g'(a^Tx)\cdot a
$$
第 $p$ 行是

$$
a_p\cdot g'(a^T x)
$$

然后对 $x_q$ 求偏导

$$
a_p\cdot g''(a^Tx)\cdot a_q
$$

合起来写应该就是

$$
\nabla^2 f(x) = aa^{T}g''(a^{T}x)
$$

（题面中说答案要简短，只需要 $11$ 个符号，有点难绷）

## Q2 \[0 points\] Positive definite matrices

首先老生常谈的是正定矩阵讨论的是 symmetric 的，即 $A^T = A$。

positive semi-definite, abbr. PSD, $A \succeq 0$.

positive definite, $A \succ 0$.

### (a)

let $z\in \mathbb R^{n}$, show that $A = z z^T$ is PSD.

$$
x^T Ax = (x^Tz)(x^Tz)^T = t^2\ge 0
$$

### (b)

let $z\in \mathbb R^{n}\backslash \{0\}$, let $A = z z^T$. What is the null-space of A? What is the rank of A?

这题感觉是考虑到如果 $Ax = 0$，那么它再左边乘一个 $x^T$，在 (a) 的基础上，会得到一个必要条件

$$
z^Tx = 0
$$

容易验证这也是充分的。从而 A 的 null-space 应当是

$$
\{x:z^Tx = 0\}
$$

至于 $A$ 的 rank，考虑到 null-space 的 dim 应该是 $n-1$，所以 A 的 rank 应该是 $1$。

### (c)

$$
(x^TB)A(x^TB)^T\ge 0
$$

## Q3 \[0 points\] Eigenvectors, eigenvalues, and the spectral theorem

### (a)

just note that

$$
AT = T\Lambda
$$

if we look at the column i of the above formula, it's just

$$
At^{(i)} = t^{(i)}\lambda_i
$$

### (b)

这里默认知道 spectral theorem。这样的话感觉和 (a) 没区别。

### (c)

只需要考虑到

$$
\Lambda = U^T A U
$$

拿一个只有第 $i$ 行为 $1$ 其它为 $0$ 的向量 $v_i$，那么 $\lambda_i(A) = v_i^T \Lambda v_i$，然后把上面代进去就是

$$
(Uv_i)^T A (Uv_i) \ge 0
$$
