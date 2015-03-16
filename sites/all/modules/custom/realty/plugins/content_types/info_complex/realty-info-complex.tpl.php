
<div class="container fin">
  <div class="col-xs-6 right-part-complex zero-padding fotorama" data-arrows="false" data-click="true" data-swipe="false" data-loop="true" data-shuffle="true" data-transition="slide" data-clicktransition="crossfade" data-nav="false">
    <?php if($photos):?>
      <?php foreach($photos as $photo):?>
        <div>
          <div class="arrow-block-left"></div>
          <div class="arrow-block-right"></div>
          <?php print $photo;?>
        </div>
      <?php endforeach;?>
    <?php endif;?>
  </div>
  <div class="col-xs-6 left-part-complex zero-padding">
    <div class="border-bottom-complex">
      <h2>
        <span class="grey-span">
          <?php print t('Developer');?>
        </span>
        <?php print $developer;?>
      </h2>
    </div>
    <div class="border-bottom-complex">
      <h2>
        <span class="grey-span">
          <?php print t('deadline');?>
        </span>
        <?php print $quarter . t('quarter');?>
        <?php print $year;?>
      </h2>
    </div>
    <div class="fix-complex-div">
      <span class="grey-span">
        <?php print t('information about the object');?>
      </span>
    </div>
    <?php if(!empty($location_description)):?>
      <?php print $location_description;?>
    <?php endif?>
  </div>
  <div class="col-xs-12 zero-padding adress-line">
    <div class="col-xs-1 adress-title">
      <?php print t('Address');?>
    </div>
    <div class="col-xs-5 adress-item">
      <?php print $address;?>
    </div>
    <div class="col-xs-6 complex-info-button-block">
      <a href="#" class="complex-info-button" data-toggle="modal" data-target=".modal_info-complex">
        <?php print t('details');?>
      </a>
    </div>
  </div>
</div>

<div class="container fin">
  <div class="col-xs-12 zero-padding complex-map">
    <?php print $map?>
  </div>
</div>
<?php print render($comment_form)?>
<!--    Modal_info-complex   -->
<div class="modal fade modal_info-complex" tabindex="-1" role="dialog" aria-labelledby="mySmallModalLabel" aria-hidden="true">
  <div class="container container-modal-info-complex zero-padding">
    <div class="col-xs-12 header-container-modal header-block">
      <?php print $findome_logo?>
      <button type="button" class="close close-modal" data-dismiss="modal" aria-hidden="true">
        <?php print $img_close;?>
      </button>
    </div>
    <div class="col-xs-12 modal-info-title">
      <?php print $complex_name?>
    </div>
    <div class="col-xs-12 modal-button">
      <ul class="apartment-tabs text-center" role="tablist">
        <li role="presentation" class="active">
          <a href="#text1"  role="tab" data-toggle="tab" aria-controls="home" aria-expanded="true">
            <?php print t('Location');?>
          </a>
        </li>
        <li role="presentation" class="">
          <a href="#text2" role="tab" data-toggle="tab" aria-controls="profile" aria-expanded="false">
            <?php print t('Architecture');?>
          </a>
        </li>
        <li role="presentation" class="">
          <a href="#text3" role="tab" data-toggle="tab" aria-controls="profile" aria-expanded="false">
            <?php print t('Accomplishment');?>
          </a>
        </li>
        <li role="presentation" class="">
          <a href="#text4" role="tab" data-toggle="tab" aria-controls="profile" aria-expanded="false">
            <?php print t('Infrastructure');?>
          </a>
        </li>
        <li role="presentation" class="">
          <a href="#text5" role="tab" data-toggle="tab" aria-controls="profile" aria-expanded="false">
            <?php print t('Service');?>
          </a>
        </li>
      </ul>
    </div>

    <div class="tab-content">
      <div role="tabpanel" class="tab-pane fade active in modal-info-text" aria-labelledby="home-tab" id="text1">
        <?php if(!empty($location_description)):?>
          <?php print $location_description;?>
        <?php endif?>
      </div>

      <div class="col-xs-12 modal-info-text tab-pane fade" id="text2" role="tabpanel" aria-labelledby="profile-tab">
        <?php if(!empty($architecture_description)):?>
          <?php print $architecture_description;?>
        <?php endif?>
      </div>

      <div class="col-xs-12 modal-info-text tab-pane fade" id="text3" role="tabpanel" aria-labelledby="profile-tab">
        <?php if(!empty($accomplishment_description)):?>
          <?php print $accomplishment_description;?>
        <?php endif?>
      </div>
      <div class="col-xs-12 modal-info-text tab-pane fade" id="text4" role="tabpanel" aria-labelledby="profile-tab">
        <?php if(!empty($infrastructure_description)):?>
          <?php print $infrastructure_description;?>
        <?php endif?>
      </div>
      <div class="col-xs-12 modal-info-text tab-pane fade" id="text5" role="tabpanel" aria-labelledby="profile-tab">
        <?php if(!empty($service_description)):?>
          <?php print $service_description;?>
        <?php endif?>
      </div>
    </div>

  </div>
</div>