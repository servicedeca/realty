<div class="container fin">
  <div class="col-xs-12 gallery-body zero-padding visual-album">
    <div class="col-xs-12">
      <?php if (isset($photos)):?>
        <?php foreach ($photos as $photo):?>
          <div class="col-xs-3 gallery-item visual-item">
            <?php print $photo;?>
          </div>
        <?php endforeach;?>
      <?php endif;?>
    </div>
  </div>
</div>