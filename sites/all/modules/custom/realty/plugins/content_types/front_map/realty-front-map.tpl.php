
<div class="container-fluid container-fix">
  <div class="row">
    <div class="col-xs-6 fifty height header-block fix">
      <div class="title-line header-text padd-bot">
        <h2>
          <?php print $image_map?>
          <?php print t('Map of buildings')?>
        </h2>
      </div>
      <div class="head-line marg-top">
      </div>
    </div>
    <div class="col-xs-6 fifty height zero-padding header-block">
      <div class="header-text padd-bot">
        <h1>
          <?php print t('Any suggestions on a map of your city')?>
        </h1>
        <h2>
          <?php print t('Find what suits you')?>
        </h2>
      </div>
    </div>
  </div>
</div>

<?php// print render($search_map_form)?>
<div id='search-map'>
  <?php print render($map);?>
</div>