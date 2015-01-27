<div class="container-fluid container-fix">
  <div class="row">
    <div class="col-xs-9 fiftyplus height zero-padding">
      <?php if($developers):?>
        <?php foreach($developers as $developer):?>
          <a href="<?php print $developer['path']?>">
            <div class="col-xs-4 z-item">
              <?php print $developer['logo']?>
            </div>
          </a>
        <?php endforeach?>
      <?php endif?>
    </div>
    <div class="col-xs-3 fiftyminus height zero-padding title-black">
      <a href="<?php print $all_developers ?>">
        <div class="col-xs-12 full-item zero-padding">
          <?php print render($micro_logo)?>
          <div class="title-block title-block-line">
            <h2>
              <?php print t('Developers')?>
            </h2>
            <p>
              <?php print t('move on');?> >
            </p>
          </div>
        </div>
      </a>
    </div>
  </div>
  <div id="dtours">
  </div>
</div>