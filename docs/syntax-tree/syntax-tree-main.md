## This is the very work in progress syntax tree for bettermark



## Image

![image](https://user-images.githubusercontent.com/76597257/126880522-85adaa0b-922d-4c98-9426-fb485a7cbed9.png)

## Credits

- <img src="https://avatars.githubusercontent.com/u/34986581" width="20px" height="20px"/>  [TheGLander](https://github.com/TheGLander) (ʐ̈ MANNNNNNN#2006):
  - Exporting SVG and PNG because my WiFi is bad

## Raw syntax

```
[BETTERMARK
  [ASTERISK
    [WHITESPACE
      [IDENTIFIER
        [EOL LIST-ASTERISK]
      ]
      [LBRACKET
        [xCHAR
          [RBRACKET
            [WHITESPACE
              [IDENTIFIER
                [EOL LIST-TASK-DONE-ASTERISK]
              ]
            ]
          ]
        ]
        [SLASH
          [RBRACKET
            [WHITESPACE
              [IDENTIFIER
                [EOL LIST-TASK-PROGRESS-ASTERISK]
              ]
            ]
          ]
        ]
        [HYPHEN
          [RBRACKET
            [WHITESPACE
              [IDENTIFIER
                [EOL LIST-TASK-DISABLED-ASTERISK]
              ]
            ]
          ]
        ]  
        [SPACE
          [RBRACKET
            [WHITESPACE
              [IDENTIFIER
                [EOL LIST-TASK-NOT-DONE-ASTERISK]
              ]
            ]
          ]
        ]
      ]
    ]
    [IDENTIFIER
      [ASTERISK ITALIC]
    ]
    [ASTERISK
      [IDENTIFIER
        [ASTERISK
          [ASTERISK BOLD]
        ]
      ]
    ]
    [OPEN-BRACKET
      [TERM
        [RBRACKET
          [COLON
            [WHITESPACE
              [IDENTIFIER ABBREVIATION]
            ]
          ]
        ]
      ]
    ]
  ]
  [HYPHEN
    [WHITESPACE
      [IDENTIFIER
        [EOL LIST-HYPHEN]
      ]
      [LBRACKET
        [x
          [RBRACKET
            [WHITESPACE
              [IDENTIFIER
                [EOL LIST-TASK-DONE-HYPHEN]
              ]
            ]
          ]
        ]
        [SLASH
          [RBRACKET
            [WHITESPACE
              [IDENTIFIER
                [EOL LIST-TASK-PROGRESS-HYPHEN]
              ]
            ]
          ]
        ]
        [HYPHEN
          [RBRACKET
            [WHITESPACE
              [IDENTIFIER
                [EOL LIST-TASK-DISABLED-HYPHEN]
              ]
            ]
          ]
        ]  
        [SPACE
          [RBRACKET
            [WHITESPACE
              [IDENTIFIER
                [EOL LIST-TASK-NOT-DONE-HYPHEN]
              ]
            ]
          ]
        ]
      ]
    ]
    [HYPHEN
      [HYPHEN
        [EOL HR-DEFAULT]
        [WHITESPACE
          [IDENTIFIER
            [WHITESPACE
              [HYPHEN
                [HYPHEN
                  [HYPHEN
                    [EOL HR-WORDS]
                  ]
                ]
              ]
            ]
          ]
        ]
      ]
    ]
  ]
  [TILDE
    [IDENTIFIER 
      [TILDE SUBSCRIPT]
    ]
    [TILDE 
      [IDENTIFIER
        [TILDE
          [TILDE STRIKETHROUGH]
        ]
      ]
    ]
  ]
  [UNDERSCORE
    [IDENTIFIER
      [UNDERSCORE UNDERLINE]
    ]
  ]
  [BANG
    [BANG
      [IDENTIFIER
        [BANG
          [BANG SPOILER]
        ]
      ]
    ]
    [LBRACKET
      [IDENTIFIER(ALT)
        [RBRACKET
          [LPAREN
            [IDENTIFIER(LINK)
              [RPAREN IMG-ALT]
              [WHITESPACE
                [IDENTIFIER(TITLE)
                  [RPAREN IMG-ALT-TITLE]
                  [WHITESPACE
                    [IDENTIFIER(SIZE-WIDTH)
                      [xCHAR
                        [IDENTIFIER(SIZE-HEIGHT)
                          [RPAREN IMG-ALT-TITLE-SIZE]
                        ]
                      ]
                    ]
                    [IDENTIFIER(ONCLICK.LINK)
                      [RPAREN IMG-ALT-TITLE-LINK]
                      [WHITESPACE
                        [IDENTIFIER(SIZE-WIDTH)
                          [xCHAR
                            [IDENTIFIER(SIZE-HEIGHT)
                              [RPAREN IMG-ALT-TITLE-LINK-SIZE]
                            ]
                          ]
                        ]
                      ]
                    ]
                  ]
                ]
                [IDENTIFIER(ONCLICK.LINK)
                  [RPAREN IMG-ALT-LINK]
                  [IDENTIFIER(SIZE-WIDTH)
                    [xCHAR
                      [IDENTIFIER(SIZE-HEIGHT)
                        [RPAREN IMG-ALT-LINK-SIZE]
                      ]
                    ]
                  ]
                ]
                [IDENTIFIER(SIZE-WIDTH)
                  [xCHAR
                    [IDENTIFIER(SIZE-HEIGHT)
                      [RPAREN IMG-ALT-SIZE]
                    ]
                  ]
                ]
              ]
            ]
          ]
        ]
      ]
      [RBRACKET
        [LPAREN
          [IDENTIFIER(LINK)
            [RPAREN IMG]
            [WHITESPACE
              [IDENTIFIER(TITLE)
                [RPAREN IMG-TITLE]
                [WHITESPACE
                  [IDENTIFIER(SIZE-WIDTH)
                    [xCHAR
                      [IDENTIFIER(SIZE-HEIGHT)
                        [RPAREN IMG-TITLE-SIZE]
                      ]
                    ]
                  ]
                  [IDENTIFIER(ONCLICK.LINK)
                    [RPAREN IMG-TITLE-LINK]
                    [WHITESPACE
                      [IDENTIFIER(SIZE-WIDTH)
                        [xCHAR
                          [IDENTIFIER(SIZE-HEIGHT)
                            [RPAREN IMG-TITLE-LINK-SIZE]
                          ]
                        ]
                      ]
                    ]
                  ]
                ]
              ]
              [IDENTIFIER(ONCLICK.LINK)
                [RPAREN IMG-LINK]
                [IDENTIFIER(SIZE-WIDTH)
                  [xCHAR
                    [IDENTIFIER(SIZE-HEIGHT)
                      [RPAREN IMG-LINK-SIZE]
                    ]
                  ]
                ]
              ]
              [IDENTIFIER(SIZE-WIDTH)
                [xCHAR
                  [IDENTIFIER(SIZE-HEIGHT)
                    [RPAREN IMG-SIZE]
                  ]
                ]
              ]
            ]
          ]
        ]
      ]
    ]
  ]
  [COLON
    [COLON
      [COLON
        [WHITESPACE
          [IDENTIFIER(CLASS-NAME)
            [BREAKLINE
              [IDENTIFIER
                [BREAKLINE
                  [COLON
                    [COLON
                      [COLON CUSTOM-CLASS]
                    ]
                  ]
                ]
              ]
            ]
          ]
        ]
        [IDENTIFIER(CLASS-NAME)
          [BREAKLINE
            [IDENTIFIER
              [BREAKLINE
                [COLON
                  [COLON
                    [COLON CUSTOM-CLASS]
                  ]
                ]
              ]
            ]
          ]
        ]
      ]
    ]
    [HASHTAG
      [COLON
        [WHITESPACE
          [IDENTIFIER HEADING-1-CENTER]
        ]
      ]
      [WHITESPACE
        [IDENTIFIER HEADING-1-LEFT]
      ]
      [HASHTAG
        [COLON
          [WHITESPACE
            [IDENTIFIER HEADING-2-CENTER]
          ]
        ]
        [WHITESPACE
          [IDENTIFIER HEADING-2-LEFT]
        ]
        [HASHTAG
          [COLON
            [WHITESPACE
              [IDENTIFIER HEADING-3-CENTER]
            ]
          ]
          [WHITESPACE
            [IDENTIFIER HEADING-3-LEFT]
          ]
          [HASHTAG
            [COLON
              [WHITESPACE
                [IDENTIFIER HEADING-4-CENTER]
              ]
            ]
            [WHITESPACE
              [IDENTIFIER HEADING-4-LEFT]
            ]
            [HASHTAG
              [COLON
                [WHITESPACE
                  [IDENTIFIER HEADING-5-CENTER]
                ]
              ]
              [WHITESPACE
                [IDENTIFIER HEADING-5-LEFT]
              ]
              [HASHTAG
                [COLON
                  [WHITESPACE
                    [IDENTIFIER HEADING-6-CENTER]
                  ]
                ]
                [WHITESPACE
                  [IDENTIFIER HEADING-6-LEFT]
                ]
              ]
            ]
          ]
        ]
      ]
    ]
  ]
  [HASHTAG
    [WHITESPACE
      [IDENTIFIER HEADING-1]
    ]
    [COLON
      [WHITESPACE
        [IDENTIFIER HEADING-1-RIGHT]
      ]
    ]
    [HASHTAG
      [WHITESPACE
        [IDENTIFIER HEADING-2]
      ]
      [COLON
        [WHITESPACE
          [IDENTIFIER HEADING-2-RIGHT]
        ]
      ]
      [HASHTAG
        [WHITESPACE
          [IDENTIFIER HEADING-3]
        ]
        [COLON
          [WHITESPACE
            [IDENTIFIER HEADING-3-RIGHT]
          ]
        ]
        [HASHTAG
          [WHITESPACE
            [IDENTIFIER HEADING-4]
          ]
          [COLON
            [WHITESPACE
              [IDENTIFIER HEADING-4-RIGHT]
            ]
          ]
          [HASHTAG
            [WHITESPACE
              [IDENTIFIER HEADING-5]
            ]
            [COLON
              [WHITESPACE
                [IDENTIFIER HEADING-5-RIGHT]
              ]
            ]
            [HASHTAG
              [WHITESPACE
                [IDENTIFIER HEADING-6]
              ]
              [COLON
                [WHITESPACE
                  [IDENTIFIER HEADING-6-RIGHT]
                ]
              ]
            ]
          ]
        ]
      ]
    ]
  ]
  [LBRACKET
    [IDENTIFIER(VISIBLE-TEXT)
      [RBRACKET
        [LPAREN
          [IDENTIFIER(LINK)
            [RPAREN LINK-ANCHOR]
          ]
        ]
      ]
    ]
  ]
  [IDENTIFIER(LINK) LINK-AUTOMATIC-URL]
  [IDENTIFIER
    [@CHAR
      [IDENTIFIER LINK-AUTOMATIC-EMAIL] 
    ]
  ]
  [RANGLEBRACKET
    [WHITESPACE
      [IDENTIFIER BLOCKQUOTE]
    ]
  ]
  [LANGLEBRACKET
    [LANGLEBRACKET
      [LANGLEBRACKET
        [WHITESPACE
          [LBRACKET
            [IDENTIFIER(TITLE)
              [RBRACKET
                [LPAREN
                  [IDENTIFIER(LINK)
                    [RPAREN
                      [BREAKLINE
                        [IDENTIFIER
                          [LANGLEBRACKET
                            [LANGLEBRACKET
                              [LANGLEBRACKET BLOCKQUOTE-FENCE-CITE-AND-TITLE]
                            ]
                          ]
                        ]
                      ]
                    ]
                  ]
                ]
                [BREAKLINE
                  [IDENTIFIER
                    [LANGLEBRACKET
                      [LANGLEBRACKET
                        [LANGLEBRACKET BLOCKQUOTE-FENCE-TITLE]
                      ]
                    ]
                  ]
                ]
              ]
            ]
          ]
          [LPAREN
            [IDENTIFIER(LINK)
              [RPAREN
                [BREAKLINE
                  [IDENTIFIER
                    [LANGLEBRACKET
                      [LANGLEBRACKET
                        [LANGLEBRACKET BLOCKQUOTE-FENCE-CITE]
                      ]
                    ]
                  ]
                ]
              ]
            ]
          ]
          [LBRACKET
            [IDENTIFIER(TITLE)
              [RBRACKET
                [LPAREN
                  [IDENTIFIER(LINK)
                    [RPAREN
                      [BREAKLINE
                        [IDENTIFIER
                          [LANGLEBRACKET
                            [LANGLEBRACKET
                              [LANGLEBRACKET BLOCKQUOTE_CITE_AND_TITLE]
                            ]
                          ]
                        ]
                      ]
                    ]
                  ]
                ]
              ]
            ]
          ]
        ]
        [BREAKLINE
          [IDENTIFIER
            [LANGLEBRACKET
              [LANGLEBRACKET
                [LANGLEBRACKET BLOCKQUOTE-FENCE-NONE]
              ]
            ]
          ]
        ]
        [LBRACKET
          [IDENTIFIER(TITLE)
            [RBRACKET
              [LPAREN
                [IDENTIFIER(LINK)
                  [RPAREN
                    [BREAKLINE
                      [IDENTIFIER
                        [LANGLEBRACKET
                          [LANGLEBRACKET
                            [LANGLEBRACKET BLOCKQUOTE-FENCE-CITE-AND-TITLE]
                          ]
                        ]
                      ]
                    ]
                  ]
                ]
              ]
              [BREAKLINE
                [IDENTIFIER
                  [LANGLEBRACKET
                    [LANGLEBRACKET
                      [LANGLEBRACKET BLOCKQUOTE-FENCE-TITLE]
                    ]
                  ]
                ]
              ]
            ]
          ]
        ]
        [LPAREN
          [IDENTIFIER(LINK)
            [RPAREN
              [BREAKLINE
                [IDENTIFIER
                  [LANGLEBRACKET
                    [LANGLEBRACKET
                      [LANGLEBRACKET BLOCKQUOTE-FENCE-CITE]
                    ]
                  ]
                ]
              ]
            ]
          ]
        ]
        [LBRACKET
          [IDENTIFIER(TITLE)
            [RBRACKET
              [LPAREN
                [IDENTIFIER(LINK)
                  [RPAREN
                    [BREAKLINE
                      [IDENTIFIER
                        [LANGLEBRACKET
                          [LANGLEBRACKET
                            [LANGLEBRACKET BLOCKQUOTE_CITE_AND_TITLE]
                          ]
                        ]
                      ]
                    ]
                  ]
                ]
              ]
            ]
          ]
        ]
      ]
    ]
  ]
]
```
