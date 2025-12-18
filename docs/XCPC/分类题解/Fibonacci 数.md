## period of Fibonacci modulo sth.

[Problem - 2033F - Codeforces](https://codeforces.com/problemset/problem/2033/F)
[Pisano period - Wikipedia](https://en.wikipedia.org/wiki/Pisano_period)


### primary analysis

??? note "the validity to consider period $\pi$"
    Another probable case is, before it enters the period, there's a path with non-zero distance. But this case can be proved impossible.
    The problem is equivalent to the order of the matrix
    
    $$
    \begin{bmatrix}
    1&1\\ 
    1&0
    \end{bmatrix}
    $$

    in the $\text{GL}_2(\mathbb{Z}_n)$, due to the initial value fits the recursion matrix coincidentally. Because of $|\det|=1$ perceives when take powers, we can prove that the identity matrix is unique.
    Denote the order as $\pi(n)$.

??? note "the validity to decompose the modulo number"

    The definition of order in number theory, where we choose the minimum integer such that
    $$
    a^{x}\equiv 1 \mod M
    $$
    leads to the conclusion that every $x'$, which satisfies the above equation, is a multiple of $x$. Otherwise, for the associative law, we have $x'\bmod M=:r<x$ as the counterexample for **minimum** choosing. Hence, it would be easy to state that
    $$
    \pi(M_1),\pi(M_2)\mid \pi(M_1M_2)
    $$
    This gives the smallest choice theoretically : 
    $$
    \operatorname{lcm}(\pi(M_1),\pi(M_2))
    $$
    And can $\pi(M_1M_2)$ select the smallest choice? Because of the minimum choosing of order $\pi$, it's motivated to verify it directly. 
    If we add a bonus constraint that, $M_1,M_2$ are coprime, notice that, the component of indentity element $1$ in $\text{GL}_2(\mathbb{Z}_n)$ is either the integer $0$ or $1$. Take the former one as an instance, if $x=k_1M_1=k_2M_2$, because of the coprime relation, it's convincible to have $x=k'M_1M_2$. The $1$ case is similar, $x=k_1M_1+1=k_2M_2+1$, then $x-1=k_1M_1=k_2M_2=k'M_1M_2$, so $x=k'M_1M_2+1$. 

    So we can resolve the $\pi$ funcion into contributions from different primes. 


Now we forget the matrix, but focus on the general formula of Fibonacci

$$
Fib_{n}=\frac{\left(\frac{1+\sqrt{5}}{2}\right)^n-\left(\frac{1-\sqrt{5}}{2}\right)^n}{\sqrt{5}}
$$

The component $\sqrt{5}$ seems suspicious. Note that the $\sqrt{5}^{2k}-(-\sqrt{5})^{2k}$ can't make contributions at all, then $2\sqrt{5}^{2k+1}$ divided by $\sqrt{5}$ to get $\sqrt{5}^{2k}=5^k$, well, make some sense. So we can equivalently consider that, yet without quadratic residue

$$
Fib_{n}=\frac{1}{2^{n-1}}\sum_{k}\binom{n}{2k+1}5^{k}
$$

Note that

$$
Fib_p\equiv\frac{1}{2^{p-1}}5^{\frac{p-1}{2}}\equiv 5^{\frac{p-1}{2}} \mod p
$$
(First equiv: the rest items are obviously 0 because the prime can't be divided by smaller ones at all. Seoncd equiv: utilize Fermat theorem for $2^{p-1}$. )


### tools from quadratic residue

Well, the form is somehow similar to Euler's criterion, which is a topic of quadratic residue. Let's develop some about it. For $1,2,\cdots,p-1$, there are exactly $1/2$ of them can be represented as $a\equiv x^2 \pmod b$, which are defined with the name quadratic residue. So the rest $1/2$ must fit the second factor to be zero, in the following formula

$$
0\equiv a^{p-1}-1\equiv \left(a^{\frac{p-1}{2}}-1\right)\left(a^{\frac{p-1}{2}}+1\right)
$$

So $a^{\frac{p-1}{2}}$ can only have two possible value, which is determined by whether it is a quadratic residue.We yet now define this as the Legendre symbol, that is 

$$
\left(\frac{a}{p}\right) := a^{\frac{p-1}{2}}\bmod p
$$

Return to what we want to calculate, we want to know

$$
\left(\frac{5}{p}\right)
$$

How to translate this to a **finite** series of cases that can be checked enumeratively , since the $p$ are **infinite**? This is the motivation of 

!!! note "quadratic reciprocity"
    For distinct odd prime $p,q$, we have
    $$
    \left(\frac{q}{p}\right)\left(\frac{p}{q}\right) = (-1)^{\frac{p-1}{2}\frac{q-1}{2}}
    $$

Hence,  

$$
\left(\frac{5}{p}\right) = \left(\frac{p}{5}\right)^{-1} (-1)^{\frac{p-1}{2}2} = \left(\frac{p}{5}\right)
$$

This can be exhaustively calculated. The final result is determined by $p\bmod 5$.

We list the enumerative results: for $1,4$, it's $1$; for $2,3$, it's $-1$.


### instant conclusions

By applying the above tools, we can see

#### p equiv 1,4 case

$$
Fib_{p}\equiv 1 \mod p
$$

$$
Fib_{p+1}\equiv \frac{1}{2^p}(\binom{p+1}{1}+\binom{p+1}{p}
5^{\frac{p-1}{2}})\equiv 1\mod p
$$

Then

$$
\begin{bmatrix}
1 & 1\\
1 & 0
\end{bmatrix}^{p-1}
\equiv 
\begin{bmatrix}
1 & 0\\
0 & 1
\end{bmatrix} 
\mod p
$$

Hence $\pi(p)\mid (p-1)$ in this case.



#### p equiv 2,3 case


This section doesn't include the equal $2$ case.

$$
Fib_{2p}\equiv \frac{1}{2}\binom{2p}{p}5^{\frac{p-1}{2}} \equiv -1 \mod p
$$

(First equiv, list $2p,2p-1,\cdots, p+1$, except $2p$ which we choose consume the front $2$ and match the $p$ in denominator to become $1$, the rest we $-p$, so the all becomes $1$. ) 

!!! warning "Fun(?) mistake"

    Why don't I just choose $-p$ for $2p$, then get

    $$
    \binom{2p}{p}\color{red}\equiv\color{black} 1
    $$

    Then combine the former method

    $$
    2\equiv \binom{2p}{p}\color{red}\equiv\color{black} 1 \mod p
    $$

    WTF? The number theory is wrong at all!

!!! Tip for the mistake
    This happens just because you assume that $p$ has inverse, but in fact not, like $1/0$ is not well-defined. So before we calculate the fraction, we must consume denominator to be an integer that has no $p$ factors at all.


$$
\begin{aligned}
Fib_{2p+1}&\equiv \frac{1}{4}(\binom{2p+1}{1}+\binom{2p+1}{p}5^{\frac{p-1}{2}}+\binom{2p+1}{2p+1}5^{p}) \\
&\equiv \frac{1}{4}(1-2+5)\equiv 1 \mod p
\end{aligned}
$$

and

$$
Fib_{2p+2}\equiv 0 \mod p
$$



!!! question "Why not calculate 2p+2 directly?"
    Of course, if we assume $p$ is sufficiently big, it's OK, just calculate 2 more items. But if not, notice that 

    $$
    \binom{2p+2}{3}
    $$

    is not equiv $0$ when $p=3$. I have mentioned the reason in Fun mistake.


$$
Fib_{2p+3}\equiv 1 \mod p
$$

Then

$$
\begin{bmatrix}
1 & 1\\
1 & 0
\end{bmatrix}^{2p+2}
\equiv 
\begin{bmatrix}
1 & 0\\
0 & 1
\end{bmatrix} 
\mod p
$$

Hence $\pi(p)\mid (2p+2)$ in this case.

#### p equal 2,5 case

It's just a bruteforce problem.

$$
\pi(2)=3,\pi(5)=20
$$

### lift the exponent for primes

Yet now we finished the single prime case. The rest work is to lift the power of single prime.

In the previous part we basically consider $\mathbb Z_n$, hence we can utilize the quadratic residue. The following part, we switch to $\mathbb Z_{n}(\sqrt{5})$, here $\sqrt{5}$ is no longer corresponding to any element in $\mathbb Z_n$, but serves with $1$ as a basis for the extension field.

For $t$ which follows

$$
F_{t}\equiv 0, F_{t+1}\equiv 1 \mod p^{k-1}
$$

here $k\ge 2$, can be equivalent to

$$
\left(\frac{1+\sqrt{5}}{2}\right)^{t}\equiv \left(\frac{1-\sqrt{5}}{2}\right)^{t} \equiv 1 \mod p^{k-1}
$$

here $1$ actually means the coefficent of $\sqrt 5$ is $0$ in $\mathbb Z_{p^{k-1}}$. The form allows us to lift the exponent of modulo number. Set

$$
\left(\frac{1+\sqrt{5}}{2}\right)^{t}=ap^{k-1}+bp^{k-1}\sqrt 5+1
$$

Then

$$
(ap^{k-1}+bp^{k-1}\sqrt 5+1)^{p}=\sum\binom{p}{j}((a+b\sqrt{5})p^{k-1})^{j}
$$

The item $\binom{p}{j}$ always contribute a factor $p$, except case that $j=p,0$. And $p^{(k-1)j}$ always greater than or equal to $p^{k}$ except $j=1,0$, futhermore, because of the contribution form $\binom{p}{1}$, makes $j=1$ case no longer an exception now. So

$$
(ap^{k-1}+bp^{k-1}\sqrt 5+1)^{p}\equiv 1 \mod p^{k}
$$

This means

$$
\pi(p^{k})\mid p\pi(p^{k-1})\mid p^{k-1}\pi(p)
$$

### final result

Because of longest common multiple merging, we extract factor $4$ from every contribution, much as possible, then denote the rest contribution as $\pi'$. Obviously the $2p+2$ can be reduced to at least $\frac{p+1}{2}<p$. After that, except $\pi'(2)=3$, every contribution from $\pi'(x)$ would not greater than $x$.

So

$$
\pi(n)\le  4 \cdot (\prod_{x|n,x\text{ is prime}} \frac{\pi'(x)}{x}) \cdot n \le 6n
$$

## Fibonacci numbers's GCD

Below is NOT necessary for the mentioned problem CF2033F. But I just throw a simple note here.

[Fibonacci GCD’s, please – Math Fun Facts](https://math.hmc.edu/funfacts/fibonacci-gcds-please/)

We have

$$
Fib_{\gcd(n,m)}=\gcd(Fib_{n},Fib_m)
$$

!!! note "Central technique to prove it: Fibonacci decomposition"
    We can resolve

    $$
    Fib_{m+n}
    $$

    into

    $$
    Fib_{m+1}Fib_{n}+Fib_{m}Fib_{n-1}
    $$

    basically due to the initial values make $n=1,2$ case obviously true, and then the recursion leads mathematical induction with respect to $n$.

Then take advantage of GCD funtion's properties:

$$
\gcd(a,b)=\gcd(a-b,b)
$$

and

$$
\gcd(c,b)=1\implies \gcd(ac,b)=\gcd(a,b)
$$

## 中文重构版证明

此处改进自原来 OI wiki 上存在问题的界面，暂时无法进一步改善。

实际上，皮萨诺周期总是不超过 $6m$。下面我们证明这一点——

### 特殊素数情况

容易验证，斐波那契数模 $2$ 的最小正周期是 $3$，模 $5$ 的最小正周期是 $20$。

（这里去除这两个情况的动机是：2 是唯一的偶素数；5 是斐波那契数列通项公式中 $\sqrt{5}$ 根号下的数。）

### 二次互反律

著名的 [二次互反律](https://en.wikipedia.org/wiki/Quadratic_reciprocity) 给出对于两个奇素数 $p,q$：

$$
\left( \frac{p}{q} \right) \left( \frac{q}{p} \right) = (-1)^{\frac{p-1}{2} \frac{q-1}{2}}
$$

其中 $\left( \frac{a}{b} \right)$ 为 [勒让德符号](https://en.wikipedia.org/wiki/Legendre_symbol)，它从数值上等于：

$$
a^{\frac{b-1}{2}} \bmod b
$$

我们代入除了 $2,5$ 之外的素数 $p$，以及 $q = 5$ 可以得知：

$$
(5^{\frac{p-1}{2}} \bmod p) \cdot (p^{\frac{5-1}{2}}\bmod 5) = (-1)^{\frac{5-1}{2}\frac{p-1}{2}} = 1
$$

因此：$p^{2} \bmod 5$ 的结果，就决定了 $5^{\frac{p-1}{2}} \bmod p$ 的结果，这是有限个情况。

### 临时借用扩域（环）

由于斐波那契数列原本就是整数，模 $p$ 的结果也会是整数。但如果我们考虑利用其通项公式：

$$
F_n = \frac{\left(\frac{1 + \sqrt{5}}{2}\right)^n - \left(\frac{1 - \sqrt{5}}{2}\right)^n}{\sqrt{5}}
$$

则需要考虑在扩域 $\mathbb{Z}_{p}(\sqrt{5})$ 下的运算。简单来说，就是考虑 $\left\{a+b\sqrt{5}:a,b\in \mathbb{Z}_{p}\right\}$ 上的运算。类似复数的实部和虚部，为了方便，我们后面可能会用 $\sqrt{5}$ 部来指代这里的 $b$，整部来指代这里的 $a$。

后面的操作之所以是良定义的，因为 $p$ 选取的是非 $2,5$ 的素数，从而 $\frac{a + b\sqrt{5}}{\sqrt{5}} = b + \frac{a}{5} \sqrt{5}$，其中 $\frac{a}{5}$ 在 $\mathbb{Z}_p$ 上是良定义的。

$\sqrt{5}$ 的偶数幂也都是良定义的，当然不会有 $\sqrt{5}$ 部。特别地，数值上 $5^\frac{p-1}{2}$ 可以用二次互反律的结论计算（依赖于 $p$ 的分类）。

结果上，$F_{n}$ 的 $\sqrt{5}$ 部总是 $0$，所以每次我们都只需要临时借用一下后，把计算结果压回 $\mathbb{Z}_p$ 即可。

后面还会碰到一个看似涉及到除以 $\sqrt{5}$ 同时除数是 $p^{k}$，这个时候就不再是扩域，而是扩环 $\mathbb{Z}_{p^k}(\sqrt{5})$，唯一除以 $\sqrt{5}$ 的时候保证了整部为 $0$，所以它等价于提取 $\sqrt{5}$ 部。

### 其它素数情况一

结论：对于奇素数 $p\equiv 1,4 \pmod 5$，$p-1$ 是斐波那契数模 $p$ 的周期。即，奇素数 $p$ 的皮萨诺周期整除 $p-1$。

证明：

此时 $5^\frac{p-1}{2} \equiv 1\pmod p$。

由二项式展开：

$$
F_p=\frac{2}{2^p\sqrt{5}}\left(\dbinom{p}{1}\sqrt{5}+\dbinom{p}{3}\sqrt{5}^3+\ldots+\dbinom{p}{p}\sqrt{5}^p\right)\equiv\sqrt{5}^{p-1}\equiv 1\pmod p
$$

$$
F_{p+1}=\frac{2}{2^{p+1}\sqrt{5}}\left(\dbinom{p+1}{1}\sqrt{5}+\dbinom{p+1}{3}\sqrt{5}^3+\ldots+\dbinom{p+1}{p}\sqrt{5}^p\right)\equiv\frac{1}{2}\left(1+\sqrt{5}^{p-1}\right)\equiv 1\pmod p
$$

因为 $F_p$ 和 $F_{p+1}$ 两项都同余于 $1$，与 $F_1$ 和 $F_2$ 一致，所以 $p-1$ 是周期。

### 其它素数情况二

结论：对于奇素数 $p\equiv 2,3 \pmod 5$，$2p+2$ 是斐波那契数模 $p$ 的周期。即，奇素数 $p$ 的皮萨诺周期整除 $2p+2$。

证明：

此时 $5^\frac{p-1}{2} \equiv -1\pmod p$。

由二项式展开：

$$
F_{2p}=\frac{2}{2^{2p}\sqrt{5}}\left(\dbinom{2p}{1}\sqrt{5}+\dbinom{2p}{3}\sqrt{5}^3+\ldots+\dbinom{2p}{2p-1}\sqrt{5}^{2p-1}\right)
$$

$$
F_{2p+1}=\frac{2}{2^{2p+1}\sqrt{5}}\left(\dbinom{2p+1}{1}\sqrt{5}+\dbinom{2p+1}{3}\sqrt{5}^3+\ldots+\dbinom{2p+1}{2p+1}\sqrt{5}^{2p+1}\right)
$$

模 $p$ 之后，在 $F_{2p}$ 式中，只有 $\dbinom{2p}{p}\equiv 2 \pmod p$ 项留了下来；在 $F_{2p+1}$ 式中，有 $\dbinom{2p+1}{1}\equiv 1 \pmod p$、$\dbinom{2p+1}{p}\equiv 2 \pmod p$、$\dbinom{2p+1}{2p+1}\equiv 1 \pmod p$，三项留了下来。

$$
F_{2p}\equiv\frac{1}{2}\dbinom{2p}{p}\sqrt{5}^{p-1}\equiv -1 \pmod p
$$

$$
F_{2p+1}\equiv\frac{1}{4}\left(\dbinom{2p+1}{1}+\dbinom{2p+1}{p}\sqrt{5}^{p-1}+\dbinom{2p+1}{2p+1}\sqrt{5}^{2p}\right)\equiv\frac{1}{4}\left(1-2+5\right)\equiv 1 \pmod p
$$

于是 $F_{2p}$ 和 $F_{2p+1}$ 两项与 $F_{-2}$ 和 $F_{-1}$ 一致，所以 $2p+2$ 是周期。

### 奇素数升幂

结论：对于奇素数 $p$，$M$ 是斐波那契数模 $p^{k-1}$ 的周期，等价于 $Mp$ 是斐波那契数模 $p^k$ 的周期。特别地，$M$ 是模 $p^{k-1}$ 的皮萨诺周期，等价于 $Mp$ 是模 $p^k$ 的皮萨诺周期。

证明：

由于：

$$
F_M=\frac{1}{\sqrt{5}}\left(\left(\frac{1+\sqrt{5}}{2}\right)^M-\left(\frac{1-\sqrt{5}}{2}\right)^M\right)\equiv 0\pmod {p^{k-1}}
$$

$$
F_{M+1}=\frac{1}{\sqrt{5}}\left(\left(\frac{1+\sqrt{5}}{2}\right)^{M+1}-\left(\frac{1-\sqrt{5}}{2}\right)^{M+1}\right)\equiv 1\pmod {p^{k-1}}
$$

因此：

$$
\left(\frac{1+\sqrt{5}}{2}\right)^M \equiv \left(\frac{1-\sqrt{5}}{2}\right)^M\pmod {p^{k-1}}
$$

$$
1\equiv\frac{1}{\sqrt{5}}\left(\frac{1+\sqrt{5}}{2}\right)^M\left(\left(\frac{1+\sqrt{5}}{2}\right)-\left(\frac{1-\sqrt{5}}{2}\right)\right)=\left(\frac{1+\sqrt{5}}{2}\right)^M\pmod {p^{k-1}}
$$

因为反方向也可以推导，所以 $M$ 是斐波那契数模 $p^{k-1}$ 的周期，等价于：

$$
\left(\frac{1+\sqrt{5}}{2}\right)^M \equiv \left(\frac{1-\sqrt{5}}{2}\right)^M\equiv 1\pmod {p^{k-1}}
$$

有了这样的充要条件，接下来的工作是做一个简单的升幂。但要注意的是通常意义下的升幂引理中需要定义质因子次数 $\nu_p$，然而我们的讨论是在扩域的基础上的，即 $\nu_p(a + b\sqrt{5})$ 无法很好地定义。所以下面我们不借助这个定理，直接做推导。

已知：

$$
\left(\frac{1+\sqrt{5}}{2}\right)^{M}=ap^{k-1}+bp^{k-1}\sqrt 5+1
$$

那么：

$$
\left(\frac{1+\sqrt{5}}{2}\right)^{Mp}=(ap^{k-1}+bp^{k-1}\sqrt 5+1)^{p}
$$

将右式二项式展开：

$$
\sum\limits_{j=0}^{p}\binom{p}{j}((a+b\sqrt{5})p^{k-1})^{j}
$$

这个式子模 $p^{k}$ 的结果中：除了 $j=0,1$ 的情况，总是有 $p^{k} | (p^{k-1})^{j}$。另外 $j=1$ 的时候 $\binom{p}{j}$ 含有 $p$ 的因子，所以恰好又能 $p^{k} | (p^{k-1}\cdot p)$。从而只有 $j=0$ 的时候会产生贡献，所以：

$$
\left(\frac{1+\sqrt{5}}{2}\right)^{Mp} \equiv 1 \pmod {p^{k}}
$$

同理：

$$
\left(\frac{1-\sqrt{5}}{2}\right)^{Mp} \equiv 1 \pmod {p^{k}}
$$

因此也等价于 $Mp$ 是斐波那契数模 $p^k$ 的周期。

因为周期等价，所以最小正周期也等价。

### 素数 2 升幂

结论：$M$ 是斐波那契数模 $2^{k-1}$ 的周期，等价于 $2M$ 是斐波那契数模 $2^k$ 的周期。特别地，$M$ 是模 $2^{k-1}$ 的皮萨诺周期，等价于 $2M$ 是模 $2^k$ 的皮萨诺周期。

证明：

这里我们绕过通项公式，使用矩阵形式，考虑到

$$
\begin{bmatrix}
F_n+1 & F_n\\
F_n & F_{n-1}
\end{bmatrix}
=
\begin{bmatrix}
1 & 1\\
1 & 0
\end{bmatrix}^{n}
$$

周期 $M$ 即：

$$
\begin{bmatrix}
1 & 1\\
1 & 0
\end{bmatrix}^{M} \equiv I \mod 2^{k-1}
$$

只需证明：

$$
\begin{bmatrix}
1 & 1\\
1 & 0
\end{bmatrix}^{2M} \equiv I \mod 2^{k}
$$

这是容易的，因为如果记

$$
\begin{bmatrix}
1 & 1\\
1 & 0
\end{bmatrix}^{M} 
= 
2^{k-1}X + I
$$

平方得

$$
2^{2(k-1)}X^2 + I + 2^{k-1+1}X \equiv I \mod 2^{k}
$$

### 合并

结论：两个互素的模数 $m_1,m_2$，有 $\pi(m_1\cdot m_2) = \operatorname{lcm}(\pi(m_1), \pi(m_2))$。

证明：只需考虑到 $(Fib_{k},Fib_{k+1}) \equiv (0,1)$ 在模 $m_1\cdot m_2$ 下成立等价于在模 $m_1,m_2$ 意义下同时成立即可。

### 合数情况

我们先对上面的推导做一个汇总：

-   $\pi(2^k) = 3\cdot 2^{k-1}, \pi(5^k) = 20\cdot 5^{k-1}$。

-   对于奇素数 $p\equiv 1,4 \pmod 5$，$\pi(p^{k})\mid (p-1)p^{k-1}$。

-   对于奇素数 $p\equiv 2,3 \pmod 5$，$\pi(p^{k})\mid (2p+2)p^{k-1}$。

在对所有 $\pi(p_i^{k_i})$ 的数值作 $\operatorname{lcm}$ 的时候，我们先尽量地先提取一个因子 $4$ 出来。这样，剩下的部分 $\pi'(p_{i}^{k_i})$ 分别是

-   $\pi'(2^{k}) \le 3 \cdot 2^{k-1} \le \frac{3}{2} \cdot 2^{k}$。

-   $\pi'(5^{k}) \le \frac{20}{4} \cdot 5^{k-1} \le 5^{k}$

-   对于奇素数 $p\equiv 1,4 \pmod 5$，$\pi'(p^{k}) \le p^{k}$。

-   对于偶素数 $p\equiv 2,3 \pmod 5$，$\pi'(p^{k}) \le \frac{p+1}{2}p^{k-1} \le p^{k}$。

所以可知

$$
\pi(m) \le 4\cdot \prod\limits_{p|m,p \text{ is prime}}\pi'(p^{\nu_p(m)}) \le 6\cdot m
$$

这就证明了上界。