## This is the very work in progress syntax tree for bettermark

## Image

![image](https://user-images.githubusercontent.com/76597257/126864171-c74efcb3-68e5-4746-869b-28a66f86ff23.png)

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
]
```
