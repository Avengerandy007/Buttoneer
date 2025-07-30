# Theme: LOOP

### Basic concept: Re-do the same tasks over and over

## Idea:

- Button pusher at corp (like stanley parable)
- Forced by your boss to do the same boring tasks every day, not even knowing why
- Slowly you become more aware of your situation
- 2 ending:
    - get tired and decide to leave
    - input so many wrong keys, your salary = 0, you kill yourself

### Art:

- Console interface

# Tech:

- Each line of text is an instance of base class
- Write intended text on screen
- Listen for key input
    - key == intended text:
        - new instrunction
    - else:
        - output error, try again
            - key != instrunction
                - lower salary

