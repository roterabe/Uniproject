function savef() {

    var data = 'data=' + document.getElementById('feedback').value;
    var feed = document.getElementById('feedback').value;
    var xmlhttp = new XMLHttpRequest();

    xmlhttp.open('POST', 'savef.php', true);

    xmlhttp.setRequestHeader('Content-type', 'application/x-www-form-urlencoded');
    xmlhttp.send(data);
    feed = document.createTextNode(feed);
    let p = document.createElement('p');
    p.className = 'laby';
    p.appendChild(feed);
    $('#wraps').append(p);
    $('#feedback').val('');
}