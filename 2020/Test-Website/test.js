
        window.onload = function () {
            var y = document.getElementById("icon").onclick = function swag() {
                var script = document.createElement("script");
                script.type = "text/javascript";
                script.src = "https://raw.githubusercontent.com/roterabe/Uniproject/master/2020/Test-Website/function.js";
                document.getElementsByTagName("head")[0].appendChild(script);
                return false;
            }
        }