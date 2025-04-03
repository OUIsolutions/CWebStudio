## HyDration Explanation

The HyDration is divided into 3 steps: first, you create the bridges, which are the functions to be called when some event gets dispatched. Then, you need to specify which elements the requirements the browser must return to that function, it can be an HTML element, a session element, etc. Then, the bridge callback handler is called, and the server returns to the browser what actions must be made.

![Hydration](graphics/images/hydration.jpg)