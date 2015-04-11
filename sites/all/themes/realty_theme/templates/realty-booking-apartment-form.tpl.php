<div class="modal fade modal_free" tabindex="-1" role="dialog" aria-labelledby="mySmallModalLabel" aria-hidden="true">
  <div class="container container-modal-booking zero-padding">
    <div class="col-xs-12 header-container-modal header-block margin-bottom-50">
      <div class="modal-text">
        <p>Бронирование квартиры</p>
      </div>
      <button type="button" class="close close-modal" data-dismiss="modal" aria-hidden="true">
        <?php print $img_close; ?>
      </button>
    </div>
    <div class="col-xs-12 text-modal-booking">
      <div id="div-info-box"></div>
    </div>
<div class="col-xs-12 comment-modal-row">
  <div class="col-xs-2 text-right zero-padding">
    <?php print $image_man; ?>
  </div>
  <div class="col-xs-10 comment-input-item">
    <?php print render($form['name'])?>
  </div>
</div>
<div class="col-xs-12 comment-modal-row margin-bottom-30">
  <div class="col-xs-2 text-right zero-padding">
    <?php print $image_phone; ?>
  </div>
  <div class="col-xs-10 comment-input-item">
    <?php print render($form['number_phone'])?>
  </div>
</div>
<div class="col-xs-12 comment-modal-row margin-bottom-30">
  <div class="col-xs-2 text-right zero-padding">
    <?php print $image_mail; ?>
  </div>
  <div class="col-xs-10 comment-input-item">
    <?php print render($form['email'])?>
  </div>
</div>

   <?php print render($form['documents'])?>
    <?php print render($form['managers'])?>

    <?php print render($form['submit'])?>
  </div>
  <div class="element-hidde">
    <?php print drupal_render_children($form);?>
  </div>
</div>
