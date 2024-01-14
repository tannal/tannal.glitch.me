



# inbox

super sampling anti-aliasing

3840 x 2160 4k

1600 x 900 


# transform

```js
// scale
[
    [Sz, 0, 0, 0],
    [0, Sy, 0, 0],
    [0, 0, Sz, 0],
    [0, 0, 0, 1],
]

// translation

[
    [1, 0, 0, tx],
    [0, 1, 0, ty],
    [0, 0, 1, tz],
    [0, 0, 0, 1],
]

// rotation X

[
    [1, 0, 0, 0],
    [0, cosθ, -sinθ, ty],
    [0, sinθ, cosθ, tz],
    [0, 0, 0, 1],
]

// rotation Y
[
    [cosθ, 0, sinθ, 0],
    [0, 1, 0, 0],
    [-sinθ, 0, cosθ, 0],
    [0, 0, 0, 1],
]

// rotation Z
[
    [cosθ, -sinθ, 0, 0],
    [sinθ, cosθ, 0, 0],
    [0, 0, 1, 0],
    [0, 0, 0, 1],
]


```


# Barycentric coordinate system


# community

https://github.com/EpicGames