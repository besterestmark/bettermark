# Chad besterestmark moment

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
**content** | __content__
```

HTML:

```html
<strong> content </strong> | <b> content <b>
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
<em> content </em> | <i> content <i>
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
<del>content</del> | <s>content</s>
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

HTML:

```html
<h1>content</h1>
<h2>content</h2>
<h3>content</h3>
<h4>content</h4>
<h5>content</h5>
<h6>content</h6>
```
