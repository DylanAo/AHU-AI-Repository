# MARKDOWN速成手册  
本手册可以直接参考，也可去参考官方的网站，下给出官方的markdown链接  
<a href="https://markdown.com.cn/basic-syntax/">Markdown官方教程</a>

## 标题文字
```markdown
# 一级标题
## 二级标题
###### 六级标题（MIN）
```

## 正常段落
```markdown
此为一行文字  
两个空格（及以上）为换行   
*倾斜文字*  
**加粗且倾斜文字**  
***加粗倾斜文字***  
~~删除线~~  
```
## 列表方法
有序列表如下:  
```markdown
1. 列表1
2. 列表2
```
无序列表如下:  
```markdown
- 列表1
- 列表2
```
## 引用
```markdown
>一层引用
>>内层引用
>空行方法(使用>单独空行)
>
>空行方法
```
## 插入公式
行中公式，可以和别的文字放在一起
```markdown
$E=mc^2$
```
独立公式
```markdown
$$
y(n) = x(n)*h(n)=\displaystyle \sum^{\infty}_{m=-\infty} x(m)h(n-m)
$$

$$E=mc^2$$
```
## 段首缩进
```Markdown
&ensp; or &#8194; 表示一个半角的空格
&emsp; or &#8195;  表示一个全角的空格
&emsp;&emsp; 两个全角的空格（用的比较多）
&nbsp; or &#160; 不断行的空白格
```
## 内嵌html实现更多功能
下划线
```
<u>underline<u>
```
插入图片或者链接  
```html
<img src="name" width="100">  
<a href="https://markdown.com.cn/basic-syntax/">Markdown官方教程</a>
```

**本文仅距离一些建议的常见的语法用于速成，Markdown语法相对简易，并不难学习。如有时间兴趣可以自行深入了解**  
