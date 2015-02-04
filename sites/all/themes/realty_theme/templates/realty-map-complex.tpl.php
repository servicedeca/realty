
<div class="col-xs-12 height zero-padding">
  <?php print render($image)?>
</div>
<div class="col-xs-12 beige-block big-height zero-padding">
  <div class="col-xs-12 quarter-item zero-padding">
    <?php print render($logo)?>
  </div>
  <div class="col-xs-12 second quarter-item zero-padding display-table">
    <div class="vertical">
      <h2>
        <?php if(!empty($node->title)):?>
          <?php print $node->title; ?>
        <?php endif;?>
      </h2>
    </div>
    <div class="gorizont-line">
    </div>
  </div>
  <div class="col-xs-12 third quarter-item zero-padding item-text-field">
    <p>
      <?php if(!empty($node->field_description)):?>
        <?php print $node->field_description['und'][0]['value'];?>
      <?php endif;?>
    </p>
  </div>
  <div class="col-xs-12 fourth button-item zero-padding item-text-field">
    <?php print render($details);?>
  </div>
</div>