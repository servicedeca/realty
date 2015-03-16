<div class="container fin">
  <div class="col-xs-12 apartment-menu zero-padding">
    <div class="col-xs-3 apartment-title zero-padding">
      <?php print $title_number;?>
    </div>
    <div class="col-xs-9 zero-padding">
      <ul class="apartment-tabs" role="tablist">
        <li role="presentation" class="active">
          <a href="#layout"  role="tab" data-toggle="tab" aria-controls="home" aria-expanded="true">
            <?php print t('Plan');?>
          </a>
        </li>
        <li role="presentation" class="">
          <a href="#layout-area" role="tab" data-toggle="tab" aria-controls="profile" aria-expanded="false">
            <?php print t('Location on the floor');?>
          </a>
        </li>
        <li role="presentation" class="">
          <a href="#layout-home" role="tab" data-toggle="tab" aria-controls="profile" aria-expanded="false">
            <?php print t('Location of the house');?>
          </a>
        </li>
        <li role="presentation" class="">
          <a href="#credit" role="tab" data-toggle="tab" aria-controls="profile" aria-expanded="false">
            <?php print t('mortgage');?>
          </a>
        </li>
      </ul>
    </div>
  </div>

  <div class="col-xs-12 zero-padding apartment-status-block">
    <div class="col-xs-1 status-icon">
      <?php print $image_status;?>
    </div>
    <?php if($field_status[0]['value'] == 1):?>
    <div class="col-xs-6 apartment-status-body apartment-status-free">
    <?php endif?>
    <?php if($field_status[0]['value'] == 0):?>
    <?php endif?>
      <?php print $status_text;?>
    </div>
    <div class="col-xs-6 bad-button-block">
      <?php print $link_modal_book;?>
    </div>
  </div>

</div>


<div class="container fin margin-bottom">

  <div class="col-xs-1 apartment-buttons-block zero-padding">
    <div class="col-xs-12 apartment-button">
      <?php print $add_comparison;?>
    </div>
    <div class="col-xs-12 apartment-button">
      <?php print $get_id;?>
    </div>
    <div class="col-xs-12 apartment-button">
      <?php print $get_doc;?>
    </div>
  </div>

  <div class="col-xs-11 zero-pading tab-content apartment-body">
    <div role="tabpanel" class="tab-pane fade active in" id="layout" aria-labelledby="home-tab">
      <div class="col-xs-8 zero-padding apartment-plan">
        <?php if(isset($apartment_plan)):?>
          <?php print $apartment_plan;?>
        <?php endif;?>
      </div>
      <div class="col-xs-4 zero-padding apartment-text">
        <h3><?php print t('Developer')?></h3>
        <p><?php print $developer?></p>
        <h3><?php print t('The residential complex');?></h3>
        <p><?php print $complex;?></p>
        <h3><?php print t('deadline')?></h3>
        <p><?php print $deadline?></p>
        <h3><?php print t('type');?></h3>
        <p><?php print $content['field_number_rooms'][0]['#markup']?></p>
        <h3><?php print t('price')?></h3>
        <p><?php print $content['field_full_cost'][0]['#markup']?></p>
        <h3><?php print t('location');?></h3>
        <p><?php print t('section number').': ' .$field_section[0]['value']?></p>
        <p><?php print t('floor').': ' .$field_apartment_floor[0]['value']?></p>
        <p><?php print t('apartment number').': ' .$field_number_apartament[0]['value']?></p>
        <h3><?php print t('square')?></h3>
        <p><?php print t('gross area').': ' .$content['field_gross_area'][0]['#markup']?></p>
        <p><?php print t('living space').': ' .$content['field_living_space'][0]['#markup']?></p>
        <h3><?php print t('Address');?></h3>
        <p><?php print $area . ' area';?></p>
        <p><?php print $address;?></p>
      </div>
    </div>
    <div role="tabpanel" class="tab-pane fade" id="layout-area" aria-labelledby="profile-tab">
      <div class="col-xs-8 zero-padding apartment-plan">
        <?php if(isset($floor_plan)):?>
          <?php print $floor_plan;?>
        <?php endif;?>
      </div>
      <div class="col-xs-4 zero-padding apartment-text">
        <h3><?php print t('Developer')?></h3>
        <p><?php print $developer?></p>
        <h3><?php print t('The residential complex');?></h3>
        <p><?php print $complex;?></p>
        <h3><?php print t('deadline')?></h3>
        <p><?php print $deadline?></p>
        <h3><?php print t('type');?></h3>
        <p><?php print $content['field_number_rooms'][0]['#markup']?></p>
        <h3><?php print t('price')?></h3>
        <p><?php print $content['field_full_cost'][0]['#markup']?></p>
        <h3><?php print t('location');?></h3>
        <p><?php print t('section number').': ' .$field_section[0]['value']?></p>
        <p><?php print t('floor').': ' .$field_apartment_floor[0]['value']?></p>
        <p><?php print t('apartment number').': ' .$field_number_apartament[0]['value']?></p>
        <h3><?php print t('square')?></h3>
        <p><?php print t('gross area').': ' .$content['field_gross_area'][0]['#markup']?></p>
        <p><?php print t('living space').': ' .$content['field_living_space'][0]['#markup']?></p>
        <h3><?php print t('Address');?></h3>
        <p><?php print $area . ' area';?></p>
        <p><?php print $address;?></p>
      </div>
    </div>
    <div role="tabpanel" class="tab-pane fade" id="layout-home" aria-labelledby="profile-tab">
      <div class="col-xs-8 zero-padding apartment-plan">
        <?php if(isset($home_plan)):?>
          <?php print $home_plan;?>
        <?php endif;?>
      </div>
      <div class="col-xs-4 zero-padding apartment-text">
        <h3><?php print t('Developer')?></h3>
        <p><?php print $developer?></p>
        <h3><?php print t('The residential complex');?></h3>
        <p><?php print $complex;?></p>
        <h3><?php print t('deadline')?></h3>
        <p><?php print $deadline?></p>
        <h3><?php print t('type');?></h3>
        <p><?php print $content['field_number_rooms'][0]['#markup']?></p>
        <h3><?php print t('price')?></h3>
        <p><?php print $content['field_full_cost'][0]['#markup']?></p>
        <h3><?php print t('location');?></h3>
        <p><?php print t('section number').': ' .$field_section[0]['value']?></p>
        <p><?php print t('floor').': ' .$field_apartment_floor[0]['value']?></p>
        <p><?php print t('apartment number').': ' .$field_number_apartament[0]['value']?></p>
        <h3><?php print t('square')?></h3>
        <p><?php print t('gross area').': ' .$content['field_gross_area'][0]['#markup']?></p>
        <p><?php print t('living space').': ' .$content['field_living_space'][0]['#markup']?></p>
        <h3><?php print t('Address');?></h3>
        <p><?php print $area . ' area';?></p>
        <p><?php print $address;?></p>
      </div>
    </div>

    <div  role="tabpanel" id="credit" aria-labelledby="profile-tab" class="col-xs-11 develop-complex zero-padding tab-pane fade margin-top-70">
      <a href="" class="col-xs-4 develop-complex-item zero-padding banks-img">
        <img src="images/sberbank.png">
      </a>
      <a href="" class="col-xs-4 develop-complex-item zero-padding banks-img">
        <img src="images/mdmbank.png">
      </a>
      <a href="" class="col-xs-4 develop-complex-item zero-padding banks-img">
        <img src="images/vtbbank.png">
      </a>
      <a href="" class="col-xs-4 develop-complex-item zero-padding banks-img">
        <img src="images/sberbank.png">
      </a>
      <a href="" class="col-xs-4 develop-complex-item zero-padding banks-img">
        <img src="images/mdmbank.png">
      </a>
      <a href="" class="col-xs-4 develop-complex-item zero-padding banks-img">
        <img src="images/vtbbank.png">
      </a>
    </div>
  </div>
</div>
