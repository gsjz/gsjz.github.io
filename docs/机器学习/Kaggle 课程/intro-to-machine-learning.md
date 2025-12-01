# intro-to-machine-learning

## Pandas

`pd`: `pandas` 库

`pd.read_csv(path_name)` 用于读取 `.csv` comma-separated-values 格式的文件，返回一个对象。

对于这个对象可以用 `.describe()` 来粗略浏览。

用 `.columns` 获得各列名，用 `.列名` 来获得某一列。

用 `.head()` 查看前若干行。

对于只认识 list 的普通 python 代码，可以用 `.tolist()` 来转化。

还有一个很 python 的语法

```python
# Create the list of features below
feature_names = ['LotArea', 'YearBuilt', '1stFlrSF', '2ndFlrSF', 'FullBath', 'BedroomAbvGr', 'TotRmsAbvGrd']

# Select data corresponding to features in feature_names
X = home_data[ feature_names ]
```

## DecisionTreeRegressor

决策树回归模型

建立对象：

```python
from sklearn.tree import DecisionTreeRegressor
# specify the model. 
#For model reproducibility, set a numeric value for random_state when specifying the model
iowa_model = DecisionTreeRegressor(random_state = 1)

# Fit the model
iowa_model.fit(X, y)
```

其中 `.fit(X, y)` 就是尝试建立从 $X$ 到 $y$ 的“映射”。

然后利用对象：

```python
predictions = iowa_model.predict(X)
print(predictions)
```

为了防止过拟合，可以考虑在定义对象时限制树深度：

```python
model = DecisionTreeRegressor(max_leaf_nodes=max_leaf_nodes, random_state=0)
```



## train_test_split

将一组数据划分一下，一些用于训练，一些用于 validation。

```python
# Import the train_test_split function and uncomment
from sklearn.model_selection import train_test_split

# fill in and uncomment
train_X, val_X, train_y, val_y = train_test_split(X, y, random_state = 1)
```

## mean_absolute_error

缩写 mae。

```python
from sklearn.metrics import mean_absolute_error
mae = mean_absolute_error(val_y, preds_val)
```

## RandomForest

原理上来说就是搞好几棵决策树，组成所谓森林，然后每次取一下它们分别预测结果的平均值。

```python
from sklearn.ensemble import RandomForestRegressor

# Define the model. Set random_state to 1
rf_model = RandomForestRegressor(random_state = 1)

# fit your model
rf_model.fit(train_X, train_y)

# Calculate the mean absolute error of your Random Forest model on the validation data
rf_val_mae = mean_absolute_error(rf_model.predict(val_X), val_y)
```
