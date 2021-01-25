$(document).ready(function() {
    var images = [
        "/Images/avatar.jpg",
        "/Images/roman.jpg",
        "/Images/profile.jpg"
    ]
    var current = 0;
    setInterval(function() {
        $("#showroom").attr("src", images[current]);
        current = (current < images.length - 1) ? current + 1 : 0;
    }, 3000);
});