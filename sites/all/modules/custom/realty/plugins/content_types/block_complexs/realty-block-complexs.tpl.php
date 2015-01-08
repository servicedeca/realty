<?php print $all_complexes?>
<?php foreach($complexes as $complex):?>
  <?php print $complex['title']?>
  <?php print render($complex['image'])?>
  <?php print $complex['description']?>
  <?php print $complex['details'] ?>
<?php endforeach;?>