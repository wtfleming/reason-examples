# bs-canvas-tilemap

Example of drawing a tilemap on a HTML canvas from Reason. Along the lines of https://developer.mozilla.org/en-US/docs/Games/Techniques/Tilemaps

# Install dependencies
```
yarn install
```

# Build
```
yarn build
```

# Build + Watch

```
yarn start
```

# Run a local dev http server
```
yarn parcel
```

Note, at least once you also need to copy over the sprites to the dist folder to get it to display in the browser. There is probably a way to get Reason to play better with Parcel for this, but for now, this will work.

```
cp tiles16.png dist/tiles16.png
```
