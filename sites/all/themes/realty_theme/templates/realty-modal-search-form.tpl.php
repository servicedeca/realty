<div class="modal fade modal-area" tabindex="-1" role="dialog" aria-labelledby="mySmallModalLabel" aria-hidden="true">
  <div class="container container-modal-city zero-padding">
    <div class="col-xs-12 header-container-modal header-block">
      <div class="modal-text">
        <p><?php print t('Select area')?></p>
      </div>
      <button type="button" class="close close-modal" data-dismiss="modal" aria-hidden="true">
        <?php print render($img_close)?>
      </button>
    </div>
    <div class="col-xs-12 list-modal-city">

      <?php foreach($areas as $key => $area):?>
        <div class="col-xs-4">
          <li>
            <input type="checkbox" id="id-area-<?php print $key?>" class="inlineCheckbox1 CheckboxArea area-<?php print $key?>" value="<?php print $key. ';' .$area?>">
            <label for="id-area-<?php print $key?>"><?php print $area; ?></label>
          </li>
        </div>
      <?php endforeach ?>

    </div>
    <div class="col-xs-12 modal-button">
      <button type="button" class="search-button modal-but" data-dismiss="modal" aria-hidden="true">
        <?php print t('select')?>
      </button>
    </div>
  </div>
</div>

<div class="modal fade modal-z" tabindex="-1" role="dialog" aria-labelledby="mySmallModalLabel" aria-hidden="true">
  <div class="container container-modal-city zero-padding">
    <div class="col-xs-12 header-container-modal header-block">
      <div class="modal-text">
        <p>
          <?php print t('Select builder')?>
        </p>
      </div>
      <button type="button" class="close close-modal" data-dismiss="modal" aria-hidden="true">
        <?php print render($img_close)?>
      </button>
    </div>
    <div class="col-xs-12 list-modal-city">
      <?php foreach($developers as $key => $developer):?>
        <div class="col-xs-4">
          <li>
            <input type="checkbox" id="id-developer-<?php print $key?>" class="inlineCheckbox1 CheckboxDeveloper developer-<?php print $key?>" value="<?php print $key. ';' .$developer?>">
            <label for="id-developer-<?php print $key?>"><?php print $developer; ?></label>
          </li>
        </div>
      <?php endforeach ?>
    </div>
    <div class="col-xs-12 modal-button">
      <button type="button" class="search-button modal-but" data-dismiss="modal" aria-hidden="true">
        <?php print t('select')?>
      </button>
    </div>
  </div>
</div>



<div class="modal fade modal-zk" tabindex="-1" role="dialog" aria-labelledby="mySmallModalLabel" aria-hidden="true">
  <div class="container container-modal-city zero-padding">
    <div class="col-xs-12 header-container-modal header-block">
      <div class="modal-text">
        <p>
          <?php print t('Select a residential complex')?>
        </p>
      </div>
      <button type="button" class="close close-modal" data-dismiss="modal" aria-hidden="true">
        <?php print render($img_close)?>
      </button>
    </div>
    <div class="col-xs-12 list-modal-city complexes-lis">
      <?php foreach($complexes as $key => $complex):?>
        <div class="col-xs-4">
          <li>
              <input type="checkbox" id="id-complex-<?php print $key?>" class="inlineCheckbox1 CheckboxComplex complex-<?php print $key?>" value="<?php print $key. ';' .$complex?>">
              <label for="id-complex-<?php print $key?>"><?php print $complex; ?></label>
          </li>
        </div>
      <?php endforeach ?>
    </div>
    <div class="col-xs-12 modal-button">
      <button type="button" class="search-button modal-but" data-dismiss="modal" aria-hidden="true">
        <?php print t('select')?>
      </button>
    </div>
  </div>
</div>


<div class="modal fade modal-type" tabindex="-1" role="dialog" aria-labelledby="mySmallModalLabel" aria-hidden="true">
  <div class="container container-modal-city zero-padding">
    <div class="col-xs-12 header-container-modal header-block">
      <div class="modal-text">
        <p>
          <?php print t('Select the type of apartment')?>
        </p>
      </div>
      <button type="button" class="close close-modal" data-dismiss="modal" aria-hidden="true">
        <?php print render($img_close)?>
      </button>
    </div>
    <div class="col-xs-12 list-modal-city">
      <?php foreach($rooms as $key => $room):?>
        <div class="col-xs-4">
          <li>
            <input type="checkbox" id="id-room-<?php print $key?>" class="inlineCheckbox1 CheckboxRoom room-<?php print $key?>" value="<?php print $key. ';' .$room?>">
            <label for="id-room-<?php print $key?>"><?php print $room;?></label>
          </li>
        </div>
      <?php endforeach ?>
    </div>
    <div class="col-xs-12 modal-button">
      <button type="button" class="search-button modal-but" data-dismiss="modal" aria-hidden="true">
        <?php print t('select')?>
      </button>
    </div>
  </div>
</div>

<div class="modal fade metro" tabindex="-1" role="dialog" aria-labelledby="mySmallModalLabel" aria-hidden="true">
  <div class="container container-modal-city zero-padding">
    <div class="col-xs-12 header-container-modal header-block">
      <div class="modal-text">
        <p>
          <?php print t('Choose the nearest metro station')?>
        </p>
      </div>
      <button type="button" class="close close-modal" data-dismiss="modal" aria-hidden="true">
        <?php print render($img_close)?>
      </button>
    </div>

    <div class="col-xs-12 list-modal-city">
      <?php foreach($metros as $key => $metro):?>
        <div class="col-xs-4">
          <li>
              <input type="checkbox" id="id-metro-<?php print $key?>" class="inlineCheckbox1 CheckboxMetro metro-<?php print $key?>" value="<?php print $key. ';' .$metro?>">
              <label for="id-metro-<?php print $key?>"><?php print $metro;?></label>
          </li>
        </div>
      <?php endforeach ?>
    </div>
    <div class="col-xs-12 modal-button">
      <button type="button" class="search-button modal-but" data-dismiss="modal" aria-hidden="true">
        <?php print t('select')?>
      </button>
    </div>
  </div>
</div>