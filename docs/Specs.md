## Italic

ID: ITALIC

Extension: None

MD:

```md
*italic*
```

HTML:

```html
<em>italic</em>
```

## Bold

ID: BOLD

Extension: None

MD:

```md
**bold**
```

HTML:

```html
<strong>bold</strong>
```

## Strikethrough

ID: STRIKETHROUGH

Extension:

MD:

```md
~~strikethrough~~
```

HTML:

```html
<s>strikethrough</s>
```

## Underline

ID: UNDERLINE

Extension: https://www.npmjs.com/package/markdown-it-underline

MD:

```md
_underline_
```

HTML:

```html
<u>underline</u>
```

## Spoiler

ID: SPOILER

Extension: https://www.npmjs.com/package/@traptitech/markdown-it-spoiler

MD:

```md
!!spoiler!!
```

HTML:

```html
<span class="spoiler">content</span>
```

CSS:

```css
/* .spoiler */
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
# heading 1

:# Left-aligned Heading 1

:#: Centred Heading 1

#: Right-aligned Heading 1

## Heading 2

:## Left-Aligned Heading 2

:##: Centred Heading 2

##: Right-alined Heading 2

### Heading 3

:### Left-Aligned Heading 3

:###: Centred Heading 3

###: Right-Aligned Heading 3

#### Heading 4

:#### Left-Aligned Heading 4

:####: Centred Heading 4

####: Right-Aligned Heading 4

##### Heading 5

:##### Left-Aligned Heading 5

:#####: Centred Heading 5

#####: Right-Aligned Heading 5

###### Heading 6

:###### Left-Aligned Heading 6

:######: Centred Heading 6

######: Right-Aligned Heading 6
```

HTML:

```html
<h1>Heading 1</h1>

<h1 align="left">Left-Aligned Heading 1</h1>

<h1 align="center">Centred Heading 1</h1>

<h1 align="right">Right-Aligned Heading 1</h1>

<h2>Heading 2</h2>

<h2 align="left">Left-Aligned Heading 2</h2>

<h2 align="center">Centred Heading 2</h2>

<h2 align="right">Right-Aligned Heading 2</h2>

<h3>Heading 3</h3>

<h3 align="left">Left-Aligned Heading 3</h3>

<h3 align="center">Centred Heading 3</h3>

<h3 align="right">Right-Aligned Heading 3</h3>

<h4>Heading 4</h4>

<h4 align="left">Left-Aligned Heading 4</h4>

<h4 align="center">Centred Heading 4</h4>

<h4 align="right">Right-Aligned Heading 4</h4>

<h5>Heading 5</h5>

<h5 align="left">Left-Aligned Heading 5</h5>

<h5 align="center">Centred Heading 5</h5>

<h5 align="right">Right-Aligned Heading 5</h5>

<h6>Heading 6</h6>

<h6 align="left">Left-Aligned Heading 6</h6>

<h6 align="center">Centred Heading 6</h6>

<h6 align="right">Right-Aligned Heading 6</h6>
```

## (WIP) Links

IDs:

LINK_ANCHOR

LINK_REFERENCE

LINK_AUTOMATIC_URL

LINK_AUTOMATIC_EMAIL

Extension: NONE

```md
[visible-text](link)

[[[!!!WILL ADD LATER!!!]]]

https://link.com

content@ema.il
```

```html
<a href="link">visible-text</a>

[[[!!!WILL ADD LATER!!!]]]	

<a href="https://link.com">https://link.com</a>

<a href="mailto:content@ema.il">content@ema.il</a>
```

## Images

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
> single-line blockquote

<<<
fenced blockquote
<<<

<<< (link)
fenced blockquote with link
<<<

<<< [title](link)
fenced blockquote with title and link
<<<

<<< [title]
fenced blockquote with title
<<<
```

HTML:

```html
<blockquote>single-line blockquote</blockquote>

<blockquote>
fenced blockquote
</blockquote>

<blockquote cite="link">
fenced blockquote with link
</blockquote>

<blockquote cite="link" title="title">
fenced blockquote with link and title
</blockquote>

<blockquote title="title">
fenced blockquote with title
</blockquote>

```

## Lists

### Unordered lists

Extension: NONE

IDs:

LIST_MINUS

LIST_ASTERISK

LIST_PLUS

MD:

```md
- list-minus

* list-asterisk

+ list-plus
```

HTML:

```html
<ul>
	<li>list-minus</li>
	<li>list-asterisk</li>
	<li>list-plus</li>
</ul>
```

### Ordered lists

IDs:

LIST_LETTER_LOWERCASE

LIST_LETTER_UPPERACSE

LIST_ROMAN_LOWERCASE

LIST_ROMAN_UPPERCASE

LIST_NUMBER

Extension: NONE

MD:

```md
a. list-letter-lowercase
b. list-letter-lowercase
c. list-letter-lowercase

A. list-letter-uppercase
B. list-letter-uppercase
C. list-letter-uppercase

i. list-roman-lowercase
ii. list-roman-lowercase
iii. list-roman-lowercase

I. list-roman-uppercase
II. list-roman-uppercase
III. list-roman-uppercase

1. list-numbered
2. list-numbered
3. list-numbered
```

HTML:

```html
<ol type="a">
	<li>list-letter-lowercase</li>
	<li>list-letter-lowercase</li>
	<li>list-letter-lowercase</li>
</ol>

<ol type="A">
	<li>list-letter-uppercase</li>
	<li>list-letter-uppercase</li>
	<li>list-letter-uppercase</li>
</ol>

<ol type="i">
	<li>list-roman-lowercase</li>
	<li>list-roman-lowercase</li>
	<li>list-roman-lowercase</li>
</ol>

<ol type="I">
	<li>list-roman-uppercase</li>
	<li>list-roman-uppercase</li>
	<li>list-roman-uppercase</li>
</ol>

<ol>
	<li>list-numbered</li>
	<li>list-numbered</li>
	<li>list-numbered</li>
</ol>
```

## (WIP) Task lists

ID:

LIST_TASK_NOT_DONE_MINUS

LIST_TASK_NOT_DONE_ASTERISK

LIST_TASK_NOT_DONE_PLUS

LIST_TASK_DONE_MINUS

LIST_TASK_DONE_ASTERISK

LIST_TASK_DONE_PLUS

LIST_TASK_PROGRESS_MINUS

LIST_TASK_PROGRESS_ASTERISK

LIST_TASK_PROGRESS_PLUS

LIST_TASK_DISABLED_MINUS

LIST_TASK_DISABLED_ASTERISK

LIST_TASK_DISABLED_PLUS

Extension: GFM

MD:

```md
- [ ] not done content

* [ ] not done content

+ [ ] not done content

- [x] done content

* [x] done content

+ [x] done content

- [/] in progress content

* [/] in progress content

+ [/] in progress content

- [-] disabled content

* [-] disabled content

+ [-] disabled content
```

HTML:

```html
<!-- PAIN -->
```

CSS:

```css
/* something */
```

NOTE: Apply custom class to checkboxes so they're easier to style


## Definition lists

ID: LIST_DEFINITION

Extension: https://github.com/markdown-it/markdown-it-deflist

MD:

```md
definitionTerm1
: definition one
: definition two

definitionTerm2
: definition one
```

HTML:

```html
<dl>
<dt>definitionTerm1</dt>
<dd>definition one</dd>
<dd>definition two</dd>
</dl>

<dl>
<dt>definitionTerm2</dt>
<dd>definition one</dd>
</dl>
```


## (WIP) Horizontal Rules

IDs:

HORIZONTAL_RULE_HYPHENS

HORIZONTAL_RULE_WORDS

Extension: NONE

MD:

```md
---

--- words inside hr ---
```

HTML:

```html
<hr class="hr-def">

<h6 class="hr-words no-num">words inside hr</h6>
```

CSS:

```css
/* something */
```

## Abbreviations

ID: ABBREVIATION

Extension: https://www.npmjs.com/package/@gerhobbelt/markdown-it-abbr

MD:

```md
*[TERM]: title
```

HTML:

```html
<abbr title="title">TERM</abbr>
```


## Code blocks

IDs:

CODE_INLINE

CODE_FENCED

Extension: NONE

MD:

~~~~
`inline code`

```
fenced code block
```
~~~~

HTML:

```html
<code>inline code</code>

<pre><code class="language-[LANG]">
fenced code block
</code></pre>
```

## Divs with custom class

ID: CUSTOM_CLASS

Extension:  [markdown-it-container](https://github.com/markdown-it/markdown-it-container)

MD:

```md
::: class-name
content inside div
:::
```

HTML:

```html
<div class="class-name">
content inside div
</div>
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

## Comment

ID: COMMENT

Extension: NONE

MD:

```md
// comment
```

HTML:

```html
<!-- comment -->
```

## Subscript

IDs:

SUBSCRIPT

SUPERSCRIPT

Extension: https://github.com/markdown-it/markdown-it-sub & https://github.com/markdown-it/markdown-it-sup

MD:

```md
~subscript~

^superscript^
```

HTML:

```html
<sub>subscript</sub>

<sup>superscript</sup>
```


## Fractions

ID: FRACTION

Extension: https://github.com/russross/blackfriday

MD:

```md
number1/number2
```

HTML:

```html
<sup>number1</sup>/<sub>number2</sub>
```

## LaTeX Math/KaTeX

IDs:

MATH_INLINE

MATH_BLOCK

Extension: https://katex.org

MD:

```md

$inline maths \alpha$

$$block maths \beta$$

```

HTML:

```html
<!-- fancy js magic -->
```
