<?php print $complex['title']?>
<?php print render($complex['main_photo'])?>
<?php print render($complex['body'])?>
<a class="but" href="#modal-pano" data-toggle="modal">
  <?php print render($complex['image_pano'])?>
</a>

<div class="modal" id="modal-pano" tabindex="-1" role="dialog" aria-labelledby="modal-panolLabel" aria-hidden="true">
  <div class="modal-content">
    <?php print render($complex['pano'])?>
  </div>
</div>