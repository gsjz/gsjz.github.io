## activation

激活函数。

引入这个东西主要是考虑到若干个线性变换复合后还是线性变换。

所以能起到弯曲决策边界的作用。

```python
# YOUR CODE HERE: Change 'relu' to 'elu', 'selu', 'swish'... or something else
activation_layer = layers.Activation('elu')

x = tf.linspace(-3.0, 3.0, 100)
y = activation_layer(x) # once created, a layer is callable just like a function

plt.figure(dpi=100)
plt.plot(x, y)
plt.xlim(-3, 3)
plt.xlabel("Input")
plt.ylabel("Output")
plt.show()
```

`activation_layer = layers.Activation('relu')`：

<img src="{{img_prefix}}20251202165153676.png"/ style="display:block; margin:0 auto; width:50%; ">

`activation_layer = layers.Activation('elu')`：

<img src="{{img_prefix}}20251202170533107.png"/ style="display:block; margin:0 auto; width:50%; ">

`activation_layer = layers.Activation('selu')`

<img src="{{img_prefix}}20251202170641041.png"/ style="display:block; margin:0 auto; width:50%; ">

`activation_layer = layers.Activation('swish')`

<img src="{{img_prefix}}20251202170709678.png"/ style="display:block; margin:0 auto; width:50%; ">

