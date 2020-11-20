//var script = document.createElement('script');
//script.src = 'https://ajax.googleapis.com/ajax/libs/jquery/3.5.1/jquery.min.js';
//script.type = 'text/javascript';
//document.getElementsByTagName('head')[0].appendChild(script);

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
    }, 3000); /*1000 = 1 sec*/
});