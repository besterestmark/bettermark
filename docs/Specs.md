## Divs with custom class

ID: CUSTOM_CLASS

Extension:  [markdown-it-container](https://github.com/markdown-it/markdown-it-container)

MD:

```md
::: className
content
:::
```

HTML:

```html
<div class="className">
content
</div>
```

## Bold

ID: BOLD

Extension: None

MD:

```md
**content**
```

HTML:

```html
<strong>content</strong>
```

## Italic

ID: ITALIC

Extension: None

MD:

```md
*content*
```

HTML:

```html
<em> content </em>
```

## Strikethrough

ID: STRIKETHROUGH

Extension:

MD:

```md
~~content~~
```

HTML:

```html
<s>content</s>
```

## Images & images with size

IDs:

IMG_ALT

IMG_TITLE

IMG_LINK

IMG_SIZE

IMG_SIZE_LINK

IMG_TITLE_SIZE

IMG_TITLE_LINK

IMG_ALT_TITLE

IMG_ALT_LINK

IMG_ALT_SIZE

IMG_ALT_TITLE_SIZE

IMG_ALT_LINK_SIZ

IMG_ALT_TITLE_LINK

IMG_TITLE_LINK_SIZE

IMG_ALT_TITLE_LINK_SIZE

Extension: https://www.npmjs.com/package/markdown-it-imsize

MD:

```md
![alt](link)

![](link "title")

![](link +onclick.link)

![](link =WidthxHeight)

![](link +onclick.link =WidthxHeight)

![](link "title" =WidthxHeight)

![](link "title" +onclick.link)

![alt](link "title")

![alt](link +onclick.link)

![alt](link =WidthxHeight)

![alt](link "title" =WidthxHeight)

![alt](link +onclick.link =WidthxHeight)

![alt](link "title" +onclick.link)

![](link "title" +onclick.link =WidthxHeight)

![alt](link "title" +onclick.link =WidthxHeight)
```

HTML:

```html
<img src="link" alt="alt"/>

<img src="link" title="title"/>

<a href="onclick.link"><img src="link"/></a>

<img src="link" width="Width" height="Height"/>

<a href="onclick.link"><img src="link" width="Width" height="Height"/></a>

<img src="link" title="title" width="Width" height="Height"/>

<a href="onclick.link"><img src="link" title="title"/></a>

<img src="link" title="title" alt="alt"/>

<a href="onclick.link"><img src="link" alt="alt"/></a>

<img src="link" title="title" alt="alt" width="Width" height="Height"/>

<a href="onclick.link"><img src="link" alt="alt" width="Width" height="Height"/></a>

<a href="onclick.link"><img src="link" title="title" alt="alt"/></a>

<a href="onclick.link"><img src="link" title="title" width="Width" height="Height"/></a>

<a href="onclick.link"><img src="link" title="title" alt="alt" width="Width" height="Height"/></a>
```

## (WIP) collapsible

ID: COLLAPSIBLE

Extension: https://www.npmjs.com/package/@gerhobbelt/markdown-it-collapsible

MD:

```md
+++ summary
hidden-content
+++
```

HTML:

```html
<details><summary>summary</summary>
hidden-content
</details>
```

### Note: this syntax is meh and should probably be changed {.WARNING}

## Abbreviations

ID: ABBREVIATIONS

Extension: https://www.npmjs.com/package/@gerhobbelt/markdown-it-abbr

MD:

```md
*[TERM]: title
```

HTML:

```html
<abbr title="title">TERM</abbr>
```

## Underline

ID: UNDERLINE

Extension: https://www.npmjs.com/package/markdown-it-underline

MD:

```md
_content_
```

HTML:

```html
<u>content</u>
```

## Spoiler

ID: SPOILER

Extension: https://www.npmjs.com/package/@traptitech/markdown-it-spoiler

MD:

```md
!!content!!
```

HTML:

```html
<span class="spoiler">content</span>
```

CSS:

```css
// something lol
```

## Headings

IDs:

HEADING_1 

HEADING_1_LEFT 

HEADING_1_CENTER 

HEADING_1_RIGHT 

HEADING_2 

HEADING_2_LEFT 

HEADING_2_CENTER 

HEADING_2_RIGHT 

HEADING_3 

HEADING_3_LEFT 

HEADING_3_CENTER 

HEADING_3_RIGHT 

HEADING_4 

HEADING_4_LEFT 

HEADING_4_CENTER 

HEADING_4_RIGHT 

HEADING_5 

HEADING_5_LEFT 

HEADING_5_CENTER 

HEADING_5_RIGHT 

HEADING_6 

HEADING_6_LEFT 

HEADING_6_CENTER 

HEADING_6_RIGHT 

Extension: NONE

MD:

```md

# content

:# content

:#: content

#: content

## content

:## content

:##: content

##: content

### content

:### content

:###: content

###: content

#### content

:#### content

:####: content

####: content

##### content

:##### content

:#####: content

#####: content

###### content


:###### content

:######: content

######: content

```

HTML:

```html
<h1>content</h1>

<h1 align="left">content</h1>

<h1 align="center">content</h1>

<h1 align="right">content</h1>

<h2>content</h2>

<h2 align="left">content</h2>

<h2 align="center">content</h2>

<h2 align="right">content</h2>

<h3>content</h3>

<h3 align="left">content</h3>

<h3 align="center">content</h3>

<h3 align="right">content</h3>

<h4>content</h4>

<h4 align="left">content</h4>

<h4 align="center">content</h4>

<h4 align="right">content</h4>

<h5>content</h5>

<h5 align="left">content</h5>

<h5 align="center">content</h5>

<h5 align="right">content</h5>

<h6>content</h6>

<h6 align="left">content</h6>

<h6 align="center">content</h6>

<h6 align="right">content</h6>

```



## Unordered list

Extension: NONE

IDs:

LIST_MINUS

LIST_ASTERISK

LIST_PLUS

MD:

```md
- content
* content
+ content
```

HTML:

```html
<ul>
	<li>content</li>
	<li>content</li>
	<li>content</li>
</ul>
```

## Lowercase Lettered ordered list

ID: LIST_LETTER_LOWERCASE

Extension: NONE

MD:

```md
a. content
b. content
c. content
```

HTML:

```html
<ol type="a">
	<li>content</li>
	<li>content</li>
	<li>content</li>
</ol>
```

## Blockquotes

IDs:

BLOCKQUOTE

BLOCKQUOTE_FENCE_NONE

BLOCKQUOTE_FENCE_CITE

BLOCKQUOTE_FENCE_CITE_AND_TITLE

BLOCKQUOTE_FENCE_TITLE

Extension: NONE

MD:

```md
> content

<<<
content
<<<

<<< (link)
content
<<<

<<< [title](link)
content
<<<

<<< [title]
content
<<<
```

HTML:

```html
<blockquote>content</blockquote>

<blockquote>
content
</blockquote>

<blockquote cite="link">
content
</blockquote>

<blockquote cite="link" title="title">
content
</blockquote>

<blockquote title="title">
content
</blockquote>

```

## Aligned headings

IDs:

HEADING_[**NUMBER**]_LEFT
HEADING_[**NUMBER]_CENTER
HEADING_[**NUMBER**]_RIGHT

Extension: NONE

MD:

```md
:# left-aligned content
:#: centred content
#: right-aligned content
```

HTML:

```html
<h1 align="left">left-aligned content</h1>
<h1 align="center">centered content</h1>
<h1 align="right">right-aligned content</h1>
```

NOTE: Default is left aligned aka no `:`

## Roman lowercase lettering list

ID: LIST_ROMAN_LOWERCASE

Extension: PANDOC

MD:

```md
i. content
ii. content
iii. content
```

HTML:

```html
<ol type="i">
  <li>content</li>
  <li>content</li>
  <li>content</li>
</ol>
```

## Roman uppercase lettering list

ID: LIST_ROMAN_UPPERCASE

Extension: PANDOC

MD:

```md
I. content
II. content
III. content
```

HTML:

```html
<ol type="I">
  <li>content</li>
  <li>content</li>
  <li>content</li>
</ol>
```

## Uppercase Lettered ordered list

ID: LIST_LETTER_UPPERCASE

Extension: NONE

MD:

```md
A. content
B. content
C. content
```

HTML:

```html
<ol type="A">
	<li>content</li>
	<li>content</li>
	<li>content</li>
</ol>
```

NOTE: Could interfere with names that have shortened first names, maybe escape them with \\ {.WARNING}

## Numbered ordered list

ID: LIST_NUMBERED

Extension: NONE

MD:

```md
1. content
2. content
3. content
```

HTML:

```html
<ol type="A">
	<li>content</li>
	<li>content</li>
	<li>content</li>
</ol>
```

## (WIP) Task lists

ID: TASK_LIST

Extension: GFM

MD:

```md
- [ ] not done content
- [x] done content
- [/] in progress content
- [-] disabled content
```

HTML:

```html
<!-- PAIN -->
```

CSS:

```css
// something lol
```

NOTE: Apply custom class to checkboxes so they're easier to style
