function savef() {
    var txt = $("#feedback").val();
    var feedbback = document.getElementById('feedback').value;
    var xmlhttp = new XMLHttpRequest();

    xmlhttp.open("POST", "savef.php", true);
    //Must add this request header to XMLHttpRequest request for POST
    xmlhttp.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
    xmlhttp.send(txt);
}