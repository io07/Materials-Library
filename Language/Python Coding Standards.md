# Python 编程规范

摘自：[Google 开源项目风格指南](http://zh-google-styleguide.readthedocs.io/en/latest/google-python-styleguide/python_style_rules/)

---

### 行长度

> <= 80个字符

不使用"\"连接，用**圆括号**， **中括号**， **花括号**连接.

```python
foo_bar(self, width, height, color='black', design=None, x='foo',
        emphasis=None, highlight=0)

if (width == 0 and height == 0 and
    color == 'red' and emphasis == 'strong'):

x = ('This will build a very long long '
     'long long long long long long string')
```

### 括号

不在**返回语句**，**条件语句**中使用括号.

### Shabang

> 大部分.py文件不必以#!作为文件的开始. 根据 PEP-394 , 程序的main文件应该以 #!/usr/bin/python2或者 #!/usr/bin/python3开始.

### 注释

#### 函数 and 方法

> 一个函数必须要有文档字符串

一个文档字符串应该这样组织: 首先是一行以句号, 问号或惊叹号结尾的概述(或者该文档字符串单纯只有一行). 接着是一个空行.

```python
def fetch_bigtable_rows(big_table, keys, other_silly_variable=None):
    """Fetches rows from a Bigtable.

    Retrieves rows pertaining to the given keys from the Table instance
    represented by big_table.  Silly things may happen if
    other_silly_variable is not None.

    Args:
        big_table: An open Bigtable Table instance.
        keys: A sequence of strings representing the key of each table row
            to fetch.
        other_silly_variable: Another optional variable, that has a much
            longer name than the other args, and which does nothing.

    Returns:
        A dict mapping keys to the corresponding table row data
        fetched. Each row is represented as a tuple of strings. For
        example:

        {'Serak': ('Rigel VII', 'Preparer'),
         'Zim': ('Irk', 'Invader'),
         'Lrrr': ('Omicron Persei 8', 'Emperor')}

        If a key from the keys argument is missing from the dictionary,
        then that row was not found in the table.

    Raises:
        IOError: An error occurred accessing the bigtable.Table object.
    """
    pass
```

#### 类

```python
class SampleClass(object):
    """Summary of class here.

    Longer class information....
    Longer class information....

    Attributes:
        likes_spam: A boolean indicating if we like SPAM or not.
        eggs: An integer count of the eggs we have laid.
    """

    def __init__(self, likes_spam=False):
        """Inits SampleClass with blah."""
        self.likes_spam = likes_spam
        self.eggs = 0

    def public_method(self):
        """Performs operation blah."""
```

### 类

> 如果一个类不继承自其它类, 就显式的从object继承. 嵌套类也一样.

### 字符串

使用**join**和**.format**来取代**'+'**和**'+='**.

1. Use double quotes around strings that are used for interpolation or that are natural language messages.
2. Single quotes for small symbol-like strings, but will break the rules if the strings contain quotes.
3. Use triple double quotes for docstrings.
4. Raw string literals for regular expressions. (r"xxx")

```python
LIGHT_MESSAGES = {
    'English': "There are %(number_of_lights)s lights.",
    'Pirate':  "Arr! Thar be %(number_of_lights)s lights."
}

def lights_message(language, number_of_lights):
    """Return a language-appropriate string reporting the light count."""
    return LIGHT_MESSAGES[language] % locals()

def is_pirate(message):
    """Return True if the given message sounds piratical."""
    return re.search(r"(?i)(arr|avast|yohoho)!", message) is not None
```

### 文件

使用**"with"语句**来管理文件.

1. 每个导入应该独占一行
2. 导入总应该放在文件顶部, 位于模块注释和文档字符串之后, 模块全局变量和常量之前
3. 导入应该按照从最通用到最不通用的顺序分组:
    1. 标准库导入
    2. 第三方库导入
    3. 应用程序指定导入
4. 每种分组中, 应该根据每个模块的完整包路径按字典序排序, 忽略大小写.

```python
import foo
from foo import bar
from foo.bar import baz
from foo.bar import Quux
from Foob import ar
```

### 命名

> module_name, package_name, ClassName, method_name, ExceptionName, function_name, GLOBAL_VAR_NAME, instance_var_name, function_parameter_name, local_var_name.

1. 所谓”内部(Internal)”表示仅模块内可用, 或者, 在类内是保护或私有的.
2. 用单下划线(_)开头表示模块变量或函数是protected的(使用import * from时不会包含).
3. 用双下划线(__)开头的实例变量或方法表示类内私有.
4. 将相关的类和顶级函数放在同一个模块里. 不像Java, 没必要限制一个类一个模块.
5. 对类名使用大写字母开头的单词(如CapWords, 即Pascal风格), 但是模块名应该用小写加下划线的方式(如lower_with_under.py). 尽管已经有很多现存的模块使用类似于CapWords.py这样的命名, 但现在已经不鼓励这样做, 因为如果模块名碰巧和类名一致, 这会让人困扰.
