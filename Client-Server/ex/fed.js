function savef() {

    var data = 'data=' + document.getElementById('feedback').value;
    var feedbback = document.getElementById('feedback').value;
    var xmlhttp = new XMLHttpRequest();

    xmlhttp.open('POST', 'savef.php', true);

    xmlhttp.setRequestHeader('Content-type', 'application/x-www-form-urlencoded');
    xmlhttp.send(data);

    $('#feedback').val('');
}