<div class="col-xs-12 zero-padding reviews-title">
  <h2>
    <?php print t('Reviews');?>
  </h2>
</div>

<div class="col-xs-12 reviews">
  <a href="#" class="col-xs-8 col-xs-offset-2 add-review-button" data-toggle="modal" data-target=".modal_comment">
    <span class="glyphicon glyphicon glyphicon-plus plus-icon" aria-hidden="true"></span>
    <?php print t('Add');?>
  </a>
  <?php print $comments;?>

  <div class="col-xs-12 recall">

  </div>
  <div class="col-xs-12 recall">

  </div>
</div>

<div class="modal fade modal_comment" tabindex="-1" role="dialog" aria-labelledby="mySmallModalLabel" aria-hidden="true">
  <div class="container container-modal-comment zero-padding">
    <div class="col-xs-12 header-container-modal header-block">
      <div class="modal-text">
        <p>
          <?php print t('Add a review');?>
        </p>
      </div>
      <button type="button" class="close close-modal" data-dismiss="modal" aria-hidden="true">
        <?php print $img_close;?>
      </button>
    </div>
    <div class="col-xs-12" id="modal-body-comment">
      <div class="col-xs-12 hint-comment-block">
      </div>
      <div class="col-xs-2 text-right zero-padding">
        <?php print $image;?>
      </div>
      <div class="col-xs-10 comment-input-item">
        <textarea id="realty-comment-form-input" class="form-control comment-textarea" rows="6" placeholder="Текст"></textarea>
      </div>
    </div>
    <button id="realty-comment-submit" type="button" class="col-xs-4 col-xs-offset-4 comment-button" data-node-id="<?php print $node->nid;?>" aria-hidden="true">
      <?php print t('Ready');?>
    </button >
  </div>
</div>
