<div class="container fin">
  <div class="col-xs-12 develop-text">
    <?php print $view->result[0]->taxonomy_term_data_description;?>
  </div>
  <div class="col-xs-12 developer-info-button-block">
    <a href="#" class="complex-info-button" data-toggle="modal" data-target=".modal_info-complex">
      <?php print t('details');?>
    </a>
  </div>
</div>
<!--    Modal_info-complex   -->
<div class="modal fade modal_info-complex" tabindex="-1" role="dialog" aria-labelledby="mySmallModalLabel" aria-hidden="true">
  <div class="container container-modal-info-complex zero-padding">
    <div class="col-xs-12 header-container-modal header-block">
      <?php print $findome_logo?>
      <button type="button" class="close close-modal" data-dismiss="modal" aria-hidden="true">
        <?php print $img_close;?>
      </button>
    </div>
    <div class="col-xs-12 developer-modal-info-title modal-info-title">
      <?php print $view->result[0]->taxonomy_term_data_name; ?>
    </div>
    <div class="col-xs-12 modal-info-text">
      <?php print $view->result[0]->taxonomy_term_data_description;?>
    </div>
  </div>
</div>
