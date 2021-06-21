# Chad besterestmark moment

## Divs with custom class

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

Extension: None

MD:

```md
*content* | _content_
```

HTML:

```html
<em> content </em> | <i> content <i>
```

## Strikethrough

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

Extension: https://www.npmjs.com/package/@gerhobbelt/markdown-it-abbr

MD:

```md
*[TERM]: title
```

HTML:

```html
<abbr title="title">TERM</abbr>
```
