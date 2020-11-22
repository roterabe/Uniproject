<?php
$post_data = $_POST['data'];
if (!empty($post_data)) {
    $dir = '.\\';
    $file = uniqid().'customer';
    $filename = $dir.$file.'.txt';
    $handle = fopen($filename, "w");
    fwrite($handle, $post_data);
    fclose($handle);

}
