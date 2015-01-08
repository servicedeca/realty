
<?php print $all_stock?>
<?php foreach ($stock as $val):?>
  <h3>
    <?php print $val['title']?>
  </h3>
  <?php print $val['description']?>
  <?php print render($val['image'])?>
<?php endforeach?>

<?php foreach ($priority_stock as $val):?>
  <h3>
    <?php print $val['title']?>
  </h3>
  <?php print $val['description']?>
  <?php print render($val['image'])?>
<?php endforeach?>