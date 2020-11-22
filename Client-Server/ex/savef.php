<?php

$allowedMethods = array(
    'POST'
);

$post_data = $_REQUEST['data'];
if (!empty($post_data)) {

    $filename = 'feedback.txt';
    $handle = fopen($filename, "w");
    fwrite($handle, $post_data);
    fclose($handle);
    echo $file;
}
?>