<div class="col-xs-12 zero-padding reviews-title">
  <h2>
    <?php print t('Reviews');?>
  </h2>
</div>

<div class="col-xs-12 reviews">
  <a href="#" class="col-xs-8 col-xs-offset-2 add-review-button" data-toggle="modal" data-target=".modal_comment">
    <span class="glyphicon glyphicon glyphicon-plus plus-icon" aria-hidden="true"></span> Добавить
  </a>
  <?php print render($content['comments']) ?>

  <div class="col-xs-12 recall">

  </div>
  <div class="col-xs-12 recall">

  </div>
</div>

<?php print render($realty_comment_form) ?>
<?php // print render($content['comments']) ?>
