<div id="newss">
</div>
<div class="container-fluid container-fix">
  <div class="row">
    <?php if(!empty($view)): ?>
      <?php print $view;?>
    <?php endif?>
    <div class="col-xs-3 fiftyminus height zero-padding title-black">
      <a href="<?php print $all_news?>">
        <div class="col-xs-12 full-item zero-padding">
          <?php print $micro_logo?>
          <div class="title-block title-block-line">
            <h2>
              <?php print t('News');?>
            </h2>
            <p>
              <?php print t('move on>'); ?>
            </p>
          </div>
        </div>
      </a>
    </div>
  </div>
</div>