<div class="container-fluid container-fix">
  <div class="row">
    <div class="col-xs-3 big-height zero-padding ">
      <a href="<?php print $all_complexes ?>">
        <div class="col-xs-12 half-item zero-padding title-black">
          <?php print $micro_logo?>
          <div class="title-block">
            <h2><?php print t('Residential')?></h2>
            <h2><?php print t('complexes')?></h2>
            <p><?php print t('move on');?></p>
          </div>
        </div>
      </a>
      <div class="col-xs-12 second-half-item zero-padding">
        <?php print $image_complexes?>
      </div>
    </div>

    <div class="col-xs-9 big-height parent fotorama" data-width="100%" data-height="100%"  data-loop="true" data-shuffle="true" data-transition="slide" data-clicktransition="crossfade" data-arrows="true" data-click="false" data-swipe="false" data-nav="false">

      <?php foreach($complexes as $complex):?>
        <div class="big-height">
          <div class="col-xs-4 beige-block zero-padding">
            <div class="col-xs-12 quarter-item zero-padding">
              <?php if (isset($complex['logo'])):?>
                <?php print $complex['logo']?>
              <?php endif?>
            </div>
            <div class="col-xs-12 second quarter-item zero-padding display-table">
              <div class="vertical">
                <h2>
                  <?php print $complex['title']?>
                </h2>
              </div>
              <div class="gorizont-line">
              </div>
            </div>
            <div class="col-xs-12 third quarter-item zero-padding item-text-field">
              <p>
                <?php if (!empty($complex['description'])):?>
                  <?php print $complex['description']?>
                <?php endif?>
              </p>
            </div>
            <div class="col-xs-12 fourth button-item zero-padding item-text-field">
              <?php print $complex['details'] ?>
            </div>
          </div>
          <div class="col-xs-8 big-height zero-padding">
            <?php print render($complex['image'])?>
          </div>
        </div>
      <?php endforeach;?>
    </div>
    <div id="card">
    </div>
  </div>
</div>

