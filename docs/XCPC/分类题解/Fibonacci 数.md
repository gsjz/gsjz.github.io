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
