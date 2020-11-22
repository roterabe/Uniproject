$(document).ready(function() {
    var images = [
        "avatar.jpg",
        "roman.jpg",
        "profile.jpg"
    ]
    var current = 0;
    setInterval(function() {
        $('#showroom').attr('src', images[current]);
        current = (current < images.length - 1) ? current + 1 : 0;
    }, 3000);
});