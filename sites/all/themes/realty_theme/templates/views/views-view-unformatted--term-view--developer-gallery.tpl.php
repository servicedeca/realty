<div class="container fin">
  <div class="col-xs-12 gallery-body zero-padding">
    <?php if (isset($albums)):?>
      <?php foreach($albums as $i => $album):?>
        <div class="col-xs-3 gallery-item album-<?php print $i?> thump-gallery">
          <?php print $album['title']?>
          <?php print $album['image_album']?>
          <?php foreach($album['photos'] as $photo):?>
            <?php print $photo;?>
          <?php endforeach;?>
        </div>
      <?php endforeach;?>
    <?php endif;?>
  </div>
</div>