$(document).ready(function() {
    Galleria.loadTheme('https://cdnjs.cloudflare.com/ajax/libs/galleria/1.6.1/themes/classic/galleria.classic.min.js');
    Galleria.configure({
        imagePosition: 'center',
        transition: "slide",
        thumbCrop: "height",
        swipe: true
    });
    Galleria.run('.galleria', {
        wait: true
    });
}());