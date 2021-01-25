function savef() {

    var data = 'data=' + document.getElementById('feedback').value;
    var feed = document.getElementById('feedback').value;
    var email = document.getElementById('fname').value;
    var xmlhttp = new XMLHttpRequest();

    xmlhttp.open('POST', 'savef.php', true);

    xmlhttp.setRequestHeader('Content-type', 'application/x-www-form-urlencoded');
    xmlhttp.send(data);

    email += ':';
    email += ' ' + feed;
    email = document.createTextNode(email);
    feed = document.createTextNode(feed);

    let p = document.createElement('p');
    let d = document.createElement('div');
    d.className = 'card';
    p.className = 'laby';
    p.setAttribute('id', 'comment');
    p.appendChild(email);
    d.appendChild(p);
    $('#wraps').append(d);
    $('#feedback').val('');
}