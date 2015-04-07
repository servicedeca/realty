<div class="col-xs-12 reg-line">
  <div class="col-xs-3 text-right zero-padding margin-top-10">
    <?php print $image_mail; ?>
  </div>
  <div class="col-xs-9 comment-input-item">
    <?php print render($form['name']);?>
  </div>
</div>
<div class="col-xs-12 reg-line">
  <div class="col-xs-3 text-right zero-padding margin-top-10">
    <?php print $image_key; ?>
  </div>
  <div class="col-xs-9 comment-input-item">
    <?php print render($form['pass']);?>
  </div>
</div>
<?php print render($form['actions'])?>

<div class="element-hidden">
  <?php print drupal_render_children($form);?>
</div>