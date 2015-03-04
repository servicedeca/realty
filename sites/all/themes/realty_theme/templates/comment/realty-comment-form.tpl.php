<div class="modal fade modal_comment" tabindex="-1" role="dialog" aria-labelledby="mySmallModalLabel" aria-hidden="true">
  <div class="container container-modal-comment zero-padding">
    <div class="col-xs-12 header-container-modal header-block margin-bottom-50">
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
      <div class="col-xs-2 text-right zero-padding">
        <?php print $image;?>
      </div>
      <div class="col-xs-10 comment-input-item">
        <textarea id="realty-comment-form-input" class="form-control comment-textarea" rows="6" placeholder="Текст"></textarea>
      </div>
    </div>
    <button id="realty-comment-submit" type="button" class="col-xs-4 col-xs-offset-4 comment-button" data-node-id="<?php print $node->nid;?>" aria-hidden="true">ГОТОВО
    </button >
      </div>
    </div>

  </div>
</div>