// Initialize array for the images
var data = ["roman.jpg", "avatar.jpg", "profile.jpg"];


Galleria.run('.galleria', {
    // Div with "galleria" class <-- we'll load images here
    dataSource: data,
    responsive: true,
    height: 0.65,
    thumbnails: 'lazy', // lazy load thumbnails, in chunkcs
    lightbox: true, // use lightbox for images on mouseclick
    lightboxTransitionSpeed: 50,
    lightboxFadeSpeed: 50,
    preload: 4
});

Galleria.ready(function() {
    // keyboard navigation 
    this.attachKeyboard({
        right: this.next,
        left: this.prev,
    });
    // lazy loading thumbnails, in chunks, for performance
    this.lazyLoadChunks(10)
});