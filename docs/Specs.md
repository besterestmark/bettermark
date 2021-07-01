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
<strong> content </strong>
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

## Image with size

ID: IMAGE_SIZE

Extension: https://www.npmjs.com/package/markdown-it-imsize

MD:

```md
![alt](link "onhover" =WidthxHeight)
```

HTML:

```html
<img src="link" title="onhover" alt="alt" width="Width" height="Height">
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

HEADING_2  

HEADING_3  

HEADING_4  

HEADING_5  

HEADING_6

Extension: NONE

MD:

```md
# content 
## content
### content
#### content
##### content
###### content
```

 align="left"

HTML:

```html
<h1 align="left">content</h1>
<h2 align="left">content</h2>
<h3 align="left">content</h3>
<h4 align="left">content</h4>
<h5 align="left">content</h5>
<h6 align="left">content</h6>
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

--- NOTE: list stuff ---

## Blockquote

ID: BLOCKQUOTE

Extension: NONE

MD:

```md
> content
```

HTML:

```html
<blockquote>content</blockquote>
```

NOTE: space after `>` is optional but recommended, also they should nest if there are multiple >>

## Fenced Blockquote

ID: BLOCKQUOTE_FENCED

Extension: NONE

MD:

```md
>>> [title](link)
content
>>>
```

HTML:

```html
<blockquote cite="link" title="title">
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

