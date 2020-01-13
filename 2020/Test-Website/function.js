function smallnav() {
    var x = document.getElementById("topnavigation");
    if (x.className === "topnav") {
        return x.className += " responsive";
    } else {
        return x.className = "topnav";
    }
}