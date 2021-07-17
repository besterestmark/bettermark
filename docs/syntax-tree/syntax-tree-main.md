## This is the very work in progress syntax tree for bettermark

## Image

![image](https://user-images.githubusercontent.com/76597257/126051678-42a9e0f4-29b6-4a0d-b022-61a4a39858e4.png)

## Raw syntax

```pain
[BETTERMARK
  [ASTERISK
  [WHITESPACE
    [IDENTIFIER
      [EOL LIST-ASTERISK]
    ]
  ]
    [WHITESPACE
				[OPEN-BRACKET
					[x
						[CLOSE-BRACKET
							[WHITESPACE
								[IDENTIFIER
									[EOL LIST-TASK-DONE-ASTERISK]
								]
							]
						]
					]
					[/
						[CLOSE-BRACKET
							[WHITESPACE
								[IDENTIFIER
									[EOL LIST-TASK-PROGRESS-ASTERISK]
								]
							]
						]
					]
					[-
						[CLOSE-BRACKET
							[WHITESPACE
								[IDENTIFIER
									[EOL LIST-TASK-DISABLED-ASTERISK]
								]
							]
						]
					]  
					[SPACE
						[CLOSE-BRACKET
							[WHITESPACE
								[IDENTIFIER
									[EOL LIST-TASK-NOT-DONE-ASTERISK]
								]
							]
						]
					]
        ]
      ]
  ]
  [HYPHEN
  -
  ]
]
```
