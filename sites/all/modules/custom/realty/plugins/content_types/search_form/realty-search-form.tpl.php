<div class="row relative">
  <div class="col-xs-9 fiftyplus height search-block zero-padding">
    <?php print render($search_form);?>
  </div>
  <div class="col-xs-9 fiftyplus big-height poster-photo parent">
    <?php print render($image);?>
  </div>
  <div class="col-xs-3 fiftyminus big-height parent">
    <div class="col-xs-12 beige-block zero-padding">
      <?php if($news_logo):?>
        <div class="col-xs-12 quarter-item zero-padding">
          <?php print $news_logo?>
        </div>
      <?php endif ?>
    </div>
    <div class="col-xs-12 second-quarter-item zero-padding item-text-field">
      <div class="arrow-left"></div>
      <p>
        <?php print $description; ?>
      </p>
      <?php print $details;?>
    </div>
    <div id="search">
    </div>
  </div>
  <div id="zk">
  </div>
</div>
<?php print $modal;?>