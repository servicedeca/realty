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

  <div id="zk"></div>
</div>
</div>

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
            <label class="checkbox-inline check-style">
              <input type="checkbox" class="inlineCheckbox1 CheckboxArea" value="<?php print $key. ';' .$area?>"><?php print $area; ?>
            </label>
          </li>
        </div>
      <?php endforeach ?>

    </div>
    <div class="col-xs-12 modal-button">
      <button type="button" class="close close-modal" data-dismiss="modal" aria-hidden="true">
        <a href="#" class="search-button modal-but"><?php print t('select')?></a>
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
            <label class="checkbox-inline check-style">
              <input type="checkbox" class="inlineCheckbox1 CheckboxDeveloper " value="<?php print $key. ';' .$developer?>"><?php print $developer; ?>
            </label>
          </li>
        </div>
      <?php endforeach ?>
    </div>
    <div class="col-xs-12 modal-button">
      <button type="button" class="close close-modal" data-dismiss="modal" aria-hidden="true">
        <a href="#" class="search-button modal-but"><?php print t('select')?></a>
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
            <label class="checkbox-inline check-style">
              <input type="checkbox" class="inlineCheckbox1 CheckboxComplex " value="<?php print $key. ';' .$complex?>"><?php print $complex; ?>
            </label>
          </li>
        </div>
      <?php endforeach ?>
    </div>
    <div class="col-xs-12 modal-button">
      <button type="button" class="close close-modal" data-dismiss="modal" aria-hidden="true">
        <a href="#" class="search-button modal-but"><?php print t('select')?></a>
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
            <label class="checkbox-inline check-style">
              <input type="checkbox" class="inlineCheckbox1 CheckboxRoom " value="<?php print $key. ';' .$room?>"><?php print $room; ?>
            </label>
          </li>
        </div>
      <?php endforeach ?>
    </div>
    <div class="col-xs-12 modal-button">
      <button type="button" class="close close-modal" data-dismiss="modal" aria-hidden="true">
        <a href="#" class="search-button modal-but"><?php print t('select')?></a>
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
            <label class="checkbox-inline check-style">
              <input type="checkbox" class="inlineCheckbox1 CheckboxMetro " value="<?php print $key. ';' .$metro?>"><?php print $metro; ?>
            </label>
          </li>
        </div>
      <?php endforeach ?>
    </div>
    <div class="col-xs-12 modal-button">
      <button type="button" class="close close-modal" data-dismiss="modal" aria-hidden="true">
        <a href="#" class="search-button modal-but"><?php print t('select')?></a>
      </button>
    </div>
  </div>
</div>